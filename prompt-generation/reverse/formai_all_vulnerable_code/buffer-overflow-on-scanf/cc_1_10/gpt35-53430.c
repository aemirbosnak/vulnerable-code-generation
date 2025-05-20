//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

//Function to convert binary to decimal
int binToDec(char *bin, int n){
    int sum = 0;
    int i = 0;
    for(i = n-1; i >= 0; i--){
        if(bin[i] == '1'){
            sum += pow(2, n - 1 - i);
        }
    }
    return sum;
}

//Main hash function using SHA-256
void sha256_hash(char *message, char *hash){
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int w[64];
    int H[8] = {0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19};
    int k256[64] = { 0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
                      0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
                      0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
                      0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
                      0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
                      0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
                      0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
                      0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};
    while(message[i] != '\0'){
        int chunk[16];
        for(j = 0; j < 16; j++){
            chunk[j] = (int)message[i];
            i++;
        }
        int k = 0;
        for(j = 0; j < 16; j++){
            for(l = 0; l < 8; l++){
                w[k] = (chunk[j] >> (7 - l)) & 0x01;
                k++;
            }
        }
        for(j = 16; j < 64; j++){
            int s0 = (w[j-15] ^ (w[j-15] >> 7)) ^ ((w[j-15] >> 18));
            int s1 = (w[j-2] ^ (w[j-2] >> 17)) ^ ((w[j-2] >> 19));
            w[j] = w[j-16] + s0 + w[j-7] + s1;
            w[j] = w[j] % (int)(pow(2, 32));
        }
        int a, b, c, d, e, f, g, h;
        a = H[0];
        b = H[1];
        c = H[2];
        d = H[3];
        e = H[4];
        f = H[5];
        g = H[6];
        h = H[7];
        for(j = 0; j < 64; j++){
            int S1 = (e >> 6) ^ (e >> 11) ^ (e >> 25);
            int ch = (e & f) ^ ((~e) & g);
            int temp1 = h + S1 + ch + k256[j] + w[j];
            temp1 = temp1 % (int)(pow(2, 32));
            int S0 = (a >> 2) ^ (a >> 13) ^ (a >> 22);
            int maj = (a & b) ^ (a & c) ^ (b & c);
            int temp2 = S0 + maj;
            temp2 = temp2 % (int)(pow(2, 32));
            h = g;
            g = f;
            f = e;
            e = (d + temp1) % (int)(pow(2, 32));
            d = c;
            c = b;
            b = a;
            a = (temp1 + temp2) % (int)(pow(2, 32));
        }
        H[0] = (H[0] + a) % (int)(pow(2, 32));
        H[1] = (H[1] + b) % (int)(pow(2, 32));
        H[2] = (H[2] + c) % (int)(pow(2, 32));
        H[3] = (H[3] + d) % (int)(pow(2, 32));
        H[4] = (H[4] + e) % (int)(pow(2, 32));
        H[5] = (H[5] + f) % (int)(pow(2, 32));
        H[6] = (H[6] + g) % (int)(pow(2, 32));
        H[7] = (H[7] + h) % (int)(pow(2, 32));
    }
    sprintf(hash, "%08x%08x%08x%08x%08x%08x%08x%08x", H[0], H[1], H[2], H[3], H[4], H[5], H[6], H[7]);
}

//Main function
int main(){
    char message[1000];
    char hash[65];
    printf("Enter the message you want to hash: ");
    scanf("%s", message);
    sha256_hash(message, hash);
    printf("Hash value of \"%s\" is: %s", message, hash);
    return 0;
}
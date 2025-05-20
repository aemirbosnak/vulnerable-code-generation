//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: satisfied
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// function to generate hash value using SHA-256 algorithm
void generateSHA256Hash(char *string, char *hashValue){

    // initial hash values
    unsigned int hash[8] = {
        0x6a09e667,
        0xbb67ae85,
        0x3c6ef372,
        0xa54ff53a,
        0x510e527f,
        0x9b05688c,
        0x1f83d9ab,
        0x5be0cd19
    };
    
    // constants for SHA-256 algorithm
    unsigned int constants[64] = {
        0x428a2f98,
        0x71374491,
        0xb5c0fbcf,
        0xe9b5dba5,
        0x3956c25b,
        0x59f111f1,
        0x923f82a4,
        0xab1c5ed5,
        0xd807aa98,
        0x12835b01,
        0x243185be,
        0x550c7dc3,
        0x72be5d74,
        0x80deb1fe,
        0x9bdc06a7,
        0xc19bf174,
        0xe49b69c1,
        0xefbe4786,
        0x0fc19dc6,
        0x240ca1cc,
        0x2de92c6f,
        0x4a7484aa,
        0x5cb0a9dc,
        0x76f988da,
        0x983e5152,
        0xa831c66d,
        0xb00327c8,
        0xbf597fc7,
        0xc6e00bf3,
        0xd5a79147,
        0x06ca6351,
        0x14292967,
        0x27b70a85,
        0x2e1b2138,
        0x4d2c6dfc,
        0x53380d13,
        0x650a7354,
        0x766a0abb,
        0x81c2c92e,
        0x92722c85,
        0xa2bfe8a1,
        0xa81a664b,
        0xc24b8b70,
        0xc76c51a3,
        0xd192e819,
        0xd6990624,
        0xf40e3585,
        0x106aa070,
        0x19a4c116,
        0x1e376c08,
        0x2748774c,
        0x34b0bcb5,
        0x391c0cb3,
        0x4ed8aa4a,
        0x5b9cca4f,
        0x682e6ff3,
        0x748f82ee,
        0x78a5636f,
        0x84c87814,
        0x8cc70208,
        0x90befffa,
        0xa4506ceb,
        0xbef9a3f7,
        0xc67178f2
    };

    unsigned int messageBlock[64];
    unsigned int temp1, temp2, a, b, c, d, e, f, g, h;
    unsigned int W[64];
    int i, j;
    unsigned long long int len = strlen(string) * 8;
    int messageLen = 0;
    int blockLen = 0;

    // padding message
    while(messageLen < strlen(string)){

        if(blockLen == 64){
            for(i=0; i<16; i++){
                W[i] = messageBlock[i];
            }
            for(i=16; i<64; i++){
                W[i] = W[i-16] + W[i-7] + (W[i-15] >> 7) + (W[i-15] << 25);
            }
            a = hash[0];
            b = hash[1];
            c = hash[2];
            d = hash[3];
            e = hash[4];
            f = hash[5];
            g = hash[6];
            h = hash[7];
            for(i=0; i<64; i++){
                temp1 = h + constants[i] + W[i] + ((e >> 6) | (e << 26)) + ((e & f) ^ (~e & g)) + d;
                temp2 = ((a >> 2) | (a << 30)) + ((a & b) ^ (a & c) ^ (b & c));
                h = g;
                g = f;
                f = e;
                e = d + temp1;
                d = c;
                c = b;
                b = a;
                a = temp1 + temp2;
            }
            hash[0] += a;
            hash[1] += b;
            hash[2] += c;
            hash[3] += d;
            hash[4] += e;
            hash[5] += f;
            hash[6] += g;
            hash[7] += h;
            blockLen = 0;
        }
        messageBlock[blockLen] = string[messageLen];
        blockLen++;
        messageLen++;
    }

    // appending 1 and extra 0's
    messageBlock[blockLen] = 0x80;
    blockLen++;
    while(blockLen != 56){
        if(blockLen == 64){
            for(i=0; i<16; i++){
                W[i] = messageBlock[i];
            }
            for(i=16; i<64; i++){
                W[i] = W[i-16] + W[i-7] + (W[i-15] >> 7) + (W[i-15] << 25);
            }
            a = hash[0];
            b = hash[1];
            c = hash[2];
            d = hash[3];
            e = hash[4];
            f = hash[5];
            g = hash[6];
            h = hash[7];
            for(i=0; i<64; i++){
                temp1 = h + constants[i] + W[i] + ((e >> 6) | (e << 26)) + ((e & f) ^ (~e & g)) + d;
                temp2 = ((a >> 2) | (a << 30)) + ((a & b) ^ (a & c) ^ (b & c));
                h = g;
                g = f;
                f = e;
                e = d + temp1;
                d = c;
                c = b;
                b = a;
                a = temp1 + temp2;
            }
            hash[0] += a;
            hash[1] += b;
            hash[2] += c;
            hash[3] += d;
            hash[4] += e;
            hash[5] += f;
            hash[6] += g;
            hash[7] += h;
            blockLen = 0;
        }
        messageBlock[blockLen] = 0;
        blockLen++;
    }

    // appending length
    messageBlock[56] = (len >> 56) & 0xff;
    messageBlock[57] = (len >> 48) & 0xff;
    messageBlock[58] = (len >> 40) & 0xff;
    messageBlock[59] = (len >> 32) & 0xff;
    messageBlock[60] = (len >> 24) & 0xff;
    messageBlock[61] = (len >> 16) & 0xff;
    messageBlock[62] = (len >> 8) & 0xff;
    messageBlock[63] = len & 0xff;

    // processing message
    for(i=0; i<16; i++){
        W[i] = messageBlock[i];
    }
    for(i=16; i<64; i++){
        W[i] = W[i-16] + W[i-7] + (W[i-15] >> 7) + (W[i-15] << 25);
    }
    a = hash[0];
    b = hash[1];
    c = hash[2];
    d = hash[3];
    e = hash[4];
    f = hash[5];
    g = hash[6];
    h = hash[7];
    for(i=0; i<64; i++){
        temp1 = h + constants[i] + W[i] + ((e >> 6) | (e << 26)) + ((e & f) ^ (~e & g)) + d;
        temp2 = ((a >> 2) | (a << 30)) + ((a & b) ^ (a & c) ^ (b & c));
        h = g;
        g = f;
        f = e;
        e = d + temp1;
        d = c;
        c = b;
        b = a;
        a = temp1 + temp2;
    }
    hash[0] += a;
    hash[1] += b;
    hash[2] += c;
    hash[3] += d;
    hash[4] += e;
    hash[5] += f;
    hash[6] += g;
    hash[7] += h;

    // convert hash value to string
    for(i=0; i<8; i++){
        sprintf(&hashValue[i*8], "%08x", hash[i]);
    }

}

// main function
int main(){

    char string[1000];
    char hashValue[65];

    printf("Enter the string to generate hash value using SHA-256 algorithm: \n");
    gets(string);

    generateSHA256Hash(string, hashValue);

    // display hash value
    printf("Hash value of the given string using SHA-256 algorithm is: \n");
    printf("%s\n", hashValue);

    return 0;

}
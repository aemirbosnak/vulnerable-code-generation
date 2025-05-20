//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCKSIZE 512  //block size of 512 bits
#define WORDSIZE 32    //word size of 32 bits

//function declaration
void sha256(char* input, unsigned int* hash);

int main() {
    char input[100];
    unsigned int hash[8] = {0};

    printf("Enter the input: ");
    scanf("%s", input);

    sha256(input, hash);

    printf("Hash value: ");
    for(int i=0; i<8; i++) {
        printf("%08x", hash[i]);    //printing the hash value in hex format
    }
    printf("\n");

    return 0;
}

void sha256(char* input, unsigned int* hash) {
    //initializing hash values
    unsigned int h0 = 0x6a09e667;
    unsigned int h1 = 0xbb67ae85;
    unsigned int h2 = 0x3c6ef372;
    unsigned int h3 = 0xa54ff53a;
    unsigned int h4 = 0x510e527f;
    unsigned int h5 = 0x9b05688c;
    unsigned int h6 = 0x1f83d9ab;
    unsigned int h7 = 0x5be0cd19;

    //preprocessing
    unsigned int messagelen = strlen(input);    //length of the message
    unsigned int bitlen = messagelen * 8;       //length of the message in bits
    unsigned int pad = 0;                       //number of padding bits
    if(messagelen % BLOCKSIZE > 448) {
        pad = 960 - (messagelen % BLOCKSIZE);   //if the data requires an extra block
    }
    else {
        pad = 448 - (messagelen % BLOCKSIZE);   //if the data fits into a single block
    }
    unsigned char* message = (unsigned char*)malloc(messagelen+pad+64);    //padded message
    memcpy(message, input, messagelen);
    *(message + messagelen) = 0x80;             //appending the bit '1' to the end of the message
    memset(message + messagelen + 1, 0, pad-7); 
    *(unsigned long long*)(message + messagelen + pad - 7) = bitlen;     //appending the length of the message in bits

    //hash calculation
    unsigned int* words = (unsigned int*)message;    //breaking the message into 32-bit words
    unsigned int wordcount = (messagelen + pad + 64) / WORDSIZE;   //total number of words

    for(int i=0; i<wordcount; i+=16) {
        unsigned int a = h0;
        unsigned int b = h1;
        unsigned int c = h2;
        unsigned int d = h3;
        unsigned int e = h4;
        unsigned int f = h5;
        unsigned int g = h6;
        unsigned int h = h7;

        //sha256 compression function
        for(int j=0; j<64; j++) {
            unsigned int T1 = h + ((e>>6)|(e<<26))^((e>>11)|(e<<21))^((e>>25)|(e<<7)) + ((e&f)^(~e&g)) + 0x428a2f98 + words[i+j%16];
            unsigned int T2 = ((a>>2)|(a<<30))^((a>>13)|(a<<19))^((a>>22)|(a<<10)) + ((a&b)^(a&c)^(b&c));
            h = g;
            g = f;
            f = e;
            e = d + T1;
            d = c;
            c = b;
            b = a;
            a = T1 + T2;
        }

        //updating the hash values
        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
        h4 += e;
        h5 += f;
        h6 += g;
        h7 += h;
    }

    //storing the final hash value
    hash[0] = h0;
    hash[1] = h1;
    hash[2] = h2;
    hash[3] = h3;
    hash[4] = h4;
    hash[5] = h5;
    hash[6] = h6;
    hash[7] = h7;
}
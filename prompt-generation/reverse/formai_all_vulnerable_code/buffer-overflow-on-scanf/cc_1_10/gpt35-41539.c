//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: paranoid
#include<stdio.h>
#include<string.h>

// function to perform left rotate operation
unsigned int left_rotate(unsigned int num, unsigned int rot) {
    return ((num << rot) | (num >> (32 - rot)));
}

// function to perform paranoid cryptographic hashing 
unsigned int paranoid_hash(char *str) {
    
    // constants for mixing the hash values
    const unsigned int k1 = 0x9e3779b1;
    const unsigned int k2 = 0x7f4a7c15;
    const unsigned int k3 = 0xf2fc5b3;
    const unsigned int k4 = 0xbf597fc7;
    
    // variables for storing hash values
    unsigned int h1 = 0x12345678;
    unsigned int h2 = 0xabcdef01;
    unsigned int h3 = 0xfedcba98;
    unsigned int h4 = 0x76543210;
    unsigned int c1, c2, c3, c4;
    
    int len = strlen(str);
    int i;
    for (i=0; i<len; i+=16) {
        
        // mixing the hash values
        c1 = (str[i+0]<<24) | (str[i+1]<<16) | (str[i+2]<<8) | (str[i+3]<<0);
        c2 = (str[i+4]<<24) | (str[i+5]<<16) | (str[i+6]<<8) | (str[i+7]<<0);
        c3 = (str[i+8]<<24) | (str[i+9]<<16) | (str[i+10]<<8) | (str[i+11]<<0);
        c4 = (str[i+12]<<24) | (str[i+13]<<16) | (str[i+14]<<8) | (str[i+15]<<0);
        
        h1 ^= left_rotate(c1 * k1, 7);
        h1 = left_rotate(h1, 11);
        h1 += h2;
        h2 ^= left_rotate(c2 * k2, 9);
        h2 = left_rotate(h2, 13);
        h2 += h3;
        h3 ^= left_rotate(c3 * k3, 9);
        h3 = left_rotate(h3, 13);
        h3 += h4;
        h4 ^= left_rotate(c4 * k4, 7);
        h4 = left_rotate(h4, 11);
        h4 += h1;
    }
    
    // final mixing of the hash values
    h1 ^= len;
    h2 ^= len;
    h3 ^= len;
    h4 ^= len;
    
    h1 += h2;
    h2 += h3;
    h3 += h4;
    h4 += h1;
    
    h1 += left_rotate(h2, 7);
    h2 += left_rotate(h3, 9);
    h3 += left_rotate(h4, 13);
    h4 += left_rotate(h1, 18);
    
    unsigned int hash_val = h1 ^ h2 ^ h3 ^ h4;
    
    return hash_val;
}

int main() {
    
    char str[100];
    printf("Enter the string to be hashed: ");
    scanf("%s", str);
    
    unsigned int hash_val = paranoid_hash(str);
    printf("The paranoid hash value of '%s' is: %x\n", str, hash_val);
    
    return 0;
}
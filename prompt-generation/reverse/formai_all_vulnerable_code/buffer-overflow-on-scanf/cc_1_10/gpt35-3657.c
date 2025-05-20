//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: statistical
#include <stdio.h>
#include <string.h>

#define POLY 0x1021

unsigned short crcTable[256];

/* Function to generate the CRC lookup table */
void generateCRCTable() {
    unsigned short i, j, crc;
    
    for(i = 0; i < 256; i++) {
        crc = (i << 8);
        
        for(j = 0; j < 8; j++) {
            if(crc & 0x8000) {
                crc = ((crc << 1) ^ POLY);
            }
            else {
                crc <<= 1;
            }
        }
        
        crcTable[i] = crc;
    }
}

/* Function to calculate the CRC checksum */
unsigned short crcChecksum(char *data, int len) {
    unsigned short crc = 0xFFFF;
    int i;
    
    for(i = 0; i < len; i++) {
        crc = (crcTable[(crc >> 8) ^ data[i]] ^ (crc << 8));
    }
    
    return crc;
}

int main() {
    char str[100];
    printf("Enter the string to calculate the CRC checksum:\n");
    scanf("%s", str);
    
    generateCRCTable();
    unsigned short crc = crcChecksum(str, strlen(str));
    
    printf("CRC Checksum: 0x%04X\n", crc);
    return 0;
}
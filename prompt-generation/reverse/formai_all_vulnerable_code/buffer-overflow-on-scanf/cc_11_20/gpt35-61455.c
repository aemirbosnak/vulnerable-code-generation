//FormAI DATASET v1.0 Category: QR code generator ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define POLY 0xD5 //x^8 + x^7 + x^6 + x^4 + x^2 + x + 1

unsigned char crc8(unsigned char* data, int len, unsigned char poly)
{
    unsigned char crc = 0;
    for (int i = 0; i < len; i++)
    {
        crc ^= data[i];
        for (int j = 0; j < 8; j++)
        {
            if (crc & 0x80)
                crc = (crc << 1) ^ poly;
            else
                crc <<= 1;
        }
    }
    return crc;
}

int main()
{
    char code[1000];
    printf("Enter the data to be encoded:\n");
    scanf("%s", code);
    int len = strlen(code);
    if (len > 7089) // Maximum capacity for a version 40, error correction level L QR code
    {
        printf("Input data is too long.\n");
        return 1;
    }
    unsigned char buf[10000];
    int pos = 0;
    int bits_added = 0;

    // Add header
    unsigned char header[21] = { 0x21, 0xF9, 0x04, 0x05, 0x00, 0x00, 0x06, 0x00, 0x2C, 0x00, 0x00,
        0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00 };
    memcpy(&buf[pos], header, sizeof(header));
    pos += sizeof(header) / sizeof(unsigned char);
    bits_added = 13 * 8;

    // Add data
    unsigned char temp_len[3] = { (len >> 16) & 0xFF, (len >> 8) & 0xFF, len & 0xFF };
    unsigned char data[10000];
    memcpy(data, temp_len, sizeof(temp_len));
    memcpy(&data[3], code, len * sizeof(char));
    len += 3;
    buf[pos] = 0x80; // ECI mode
    buf[pos + 1] = 0x26; // UTF-8 encoding
    pos += 2;
    bits_added += 16;
    for (int i = 0; i < len; i += 2)
    {
        unsigned int temp;
        if (i == len - 1)
            temp = data[i];
        else
            temp = ((unsigned int)data[i] << 8) | data[i + 1];
        unsigned char first_byte = (temp >> 7) & 0xFF;
        unsigned char second_byte = temp & 0x7F;
        buf[pos] = (first_byte << 1) | (i == len - 1 ? 1 : 0);
        buf[pos + 1] = second_byte;
        pos += 2;
        bits_added += 15;
    }

    // Add terminator
    buf[pos++] = 0x00;
    buf[pos++] = 0x3B;
    bits_added += 12;

    // Add padding
    while ((bits_added & 7) != 0)
    {
        buf[pos++] = 0;
        bits_added += 1;
    }

    // Add CRC
    unsigned char crc = crc8(buf, pos, POLY);
    buf[pos++] = crc;
    bits_added += 8;

    // Generate QR code
    int version = 40;
    unsigned char ecl = 1; // Error correction level: L
    int width = 17 + 4 * version;
    int byte_pos = 0;
    unsigned char pixel = 0;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || i == width - 1 || j == 0 || j == width - 1 || (i >= 6 && i < width - 6 && j >= 6 && j < width - 6 && ((i - 6) % 4 == 0) == ((j - 6) % 4 == 0)))
            {
                pixel = 0;
            }
            else
            {
                if ((byte_pos >> 3) < pos)
                    pixel = (buf[byte_pos >> 3] >> (7 - (byte_pos & 7))) & 0x01;
                else
                    pixel = 0;
                byte_pos++;
            }
            if (pixel == 0)
                printf("\033[47m\033[30m  \033[0m");
            else
                printf("\033[40m  \033[0m");
        }
        printf("\n");
    }

    return 0;
}
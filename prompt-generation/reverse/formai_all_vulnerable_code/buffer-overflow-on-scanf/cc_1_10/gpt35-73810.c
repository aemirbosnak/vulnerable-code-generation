//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to convert integer to binary */
void int_to_bin(int num, char* bin_str, int len)
{
    int i;
    for (i = len - 1; i >= 0; i--)
    {
        bin_str[i] = (num % 2) + '0';
        num /= 2;
    }
    bin_str[len] = '\0';
}

/* Function to convert binary to integer */
int bin_to_int(char* bin_str, int len)
{
    int i, num = 0;
    for (i = 0; i < len; i++)
    {
        num = num * 2 + (bin_str[i] - '0');
    }
    return num;
}

int main()
{
    int msg_len, i, j, num_of_bits, key, bin_len;
    char message[100], watermark[100], bin_msg[800], bin_watermark[800];
    
    /* Read message from user */
    printf("Enter message: ");
    scanf("%[^\n]s", message);
    
    /* Read watermark from user */
    printf("Enter watermark: ");
    scanf("\n%[^\n]s", watermark);
    
    /* Convert message and watermark to binary strings */
    for (i = 0, j = 0; message[i] != '\0'; i++)
    {
        int_to_bin(message[i], &bin_msg[j], 8);
        j += 8;
    }
    msg_len = i;
    bin_len = j;
    
    for (i = 0, j = 0; watermark[i] != '\0'; i++)
    {
        int_to_bin(watermark[i], &bin_watermark[j], 8);
        j += 8;
    }
    num_of_bits = i * 8;
    
    /* Generate random key */
    srand(time(NULL));
    key = rand() % (bin_len - num_of_bits);
    
    /* Insert watermark into message */
    for (i = 0; i < num_of_bits; i++)
    {
        bin_msg[key + i] = bin_watermark[i];
    }
    
    /* Convert modified binary string back to message */
    for (i = 0, j = 0; i < bin_len; i += 8)
    {
        message[j] = bin_to_int(&bin_msg[i], 8);
        j++;
    }
    message[j] = '\0';
    
    printf("Watermark inserted successfully!\n");
    printf("Modified message: %s\n", message);
    
    return 0;
}
//FormAI DATASET v1.0 Category: Image Steganography ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_CHAR 10000

// Function to convert integer to binary string
void int2bin(int num, char *bin, int len)
{
    int i;
    for (i = len - 1; i >= 0; i--)
    {
        if (num & (1 << i))
            *(bin++) = '1';
        else
            *(bin++) = '0';
    }
    *bin = '\0';
}

// Function to convert binary string to integer
int bin2int(char *bin)
{
    int len = strlen(bin), num = 0, i;
    for (i = 0; i < len; i++)
    {
        if (bin[len - 1 - i] == '1')
            num += pow(2, i);
    }
    return num;
}

// Function to hide message inside image
void hide_message(char *msg, char *img_path)
{
    FILE *fp_img, *fp_out;
    fp_img = fopen(img_path, "rb");
    fp_out = fopen("output.bmp", "wb");
    if (fp_img == NULL || fp_out == NULL)
    {
        printf("Error opening files!\n");
        exit(1);
    }
    char buf[MAX_CHAR];
    int len_msg = strlen(msg), i, j = 0;
    // Read header of BMP file and write to output file
    for (i = 0; i < 54; i++)
    {
        buf[i] = getc(fp_img);
        putc(buf[i], fp_out);
    }
    // Hide length of message in first 32 bits
    char len_bin[32 + 1];
    int2bin(len_msg, len_bin, 32);
    for (i = 0; i < 32; i += 3)
    {
        if (len_bin[i] == '0' && len_bin[i + 1] == '0' && len_bin[i + 2] == '0')
        {
            buf[j] &= ~(1 << 0);
            buf[j] &= ~(1 << 1);
        }
        else if (len_bin[i] == '0' && len_bin[i + 1] == '0' && len_bin[i + 2] == '1')
        {
            buf[j] &= ~(1 << 0);
            buf[j] |= (1 << 1);
        }
        else if (len_bin[i] == '0' && len_bin[i + 1] == '1' && len_bin[i + 2] == '0')
        {
            buf[j] |= (1 << 0);
            buf[j] &= ~(1 << 1);
        }
        else if (len_bin[i] == '0' && len_bin[i + 1] == '1' && len_bin[i + 2] == '1')
        {
            buf[j] |= (1 << 0);
            buf[j] |= (1 << 1);
        }
        else if (len_bin[i] == '1' && len_bin[i + 1] == '0' && len_bin[i + 2] == '0')
        {
            buf[j] &= ~(1 << 2);
            buf[j] &= ~(1 << 3);
        }
        else if (len_bin[i] == '1' && len_bin[i + 1] == '0' && len_bin[i + 2] == '1')
        {
            buf[j] &= ~(1 << 2);
            buf[j] |= (1 << 3);
        }
        else if (len_bin[i] == '1' && len_bin[i + 1] == '1' && len_bin[i + 2] == '0')
        {
            buf[j] |= (1 << 2);
            buf[j] &= ~(1 << 3);
        }
        else if (len_bin[i] == '1' && len_bin[i + 1] == '1' && len_bin[i + 2] == '1')
        {
            buf[j] |= (1 << 2);
            buf[j] |= (1 << 3);
        }
        j++;
    }
    // Hide message in remaining bytes
    for (i = 0; i < len_msg; i++)
    {
        int2bin(msg[i], buf + j, 8);
        j += 8;
    }
    // Write modified bytes to output file
    while (!feof(fp_img))
    {
        buf[0] = getc(fp_img);
        putc(buf[0], fp_out);
    }
    // Close files
    fclose(fp_img);
    fclose(fp_out);
}

// Function to extract message from image
void extract_message(char *msg_path, char *img_path)
{
    FILE *fp_msg, *fp_img;
    fp_msg = fopen(msg_path, "wb");
    fp_img = fopen(img_path, "rb");
    if (fp_msg == NULL || fp_img == NULL)
    {
        printf("Error opening files!\n");
        exit(1);
    }
    char buf[MAX_CHAR], len_bin[32 + 1], msg[MAX_CHAR];
    int len_msg, i, j = 0;
    // Read header of BMP file
    for (i = 0; i < 54; i++)
        buf[i] = getc(fp_img);
    // Extract length of message from first 32 bits
    for (i = 0; i < 32; i += 3)
    {
        if ((buf[j] & (1 << 0)) == 0 && (buf[j] & (1 << 1)) == 0)
            len_bin[i] = len_bin[i + 1] = len_bin[i + 2] = '0';
        else if ((buf[j] & (1 << 0)) == 0 && (buf[j] & (1 << 1)) == 1)
            len_bin[i] = len_bin[i + 1] = '0', len_bin[i + 2] = '1';
        else if ((buf[j] & (1 << 0)) == 1 && (buf[j] & (1 << 1)) == 0)
            len_bin[i] = '0', len_bin[i + 1] = len_bin[i + 2] = '1';
        else if ((buf[j] & (1 << 0)) == 1 && (buf[j] & (1 << 1)) == 1)
            len_bin[i] = len_bin[i + 1] = len_bin[i + 2] = '1';
        if ((buf[j] & (1 << 2)) == 0 && (buf[j] & (1 << 3)) == 0)
            len_bin[i + 3] = len_bin[i + 4] = len_bin[i + 5] = '0';
        else if ((buf[j] & (1 << 2)) == 0 && (buf[j] & (1 << 3)) == 1)
            len_bin[i + 3] = len_bin[i + 4] = '0', len_bin[i + 5] = '1';
        else if ((buf[j] & (1 << 2)) == 1 && (buf[j] & (1 << 3)) == 0)
            len_bin[i + 3] = '0', len_bin[i + 4] = len_bin[i + 5] = '1';
        else if ((buf[j] & (1 << 2)) == 1 && (buf[j] & (1 << 3)) == 1)
            len_bin[i + 3] = len_bin[i + 4] = len_bin[i + 5] = '1';
        j++;
    }
    len_msg = bin2int(len_bin);
    // Extract message from remaining bytes
    while (!feof(fp_img))
    {
        buf[0] = getc(fp_img);
        if (feof(fp_img))
            break;
        if (j > 54 && j <= (54 + len_msg * 8))
        {
            int2bin(buf[0], msg + (j - 54 - 1) / 8 * 8, 8);
        }
        j++;
    }
    msg[len_msg] = '\0';
    // Write extracted message to output file
    fprintf(fp_msg, "%s", msg);
    // Close files
    fclose(fp_msg);
    fclose(fp_img);
}

int main()
{
    int choice;
    char msg[MAX_CHAR], img_path[MAX_CHAR], msg_path[MAX_CHAR];
    printf("This is a multiplayer C image steganography program.\n");
    while (1)
    {
        printf("\nPlease choose an option:\n1. Hide message in image\n2. Extract message from image\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter path of image file: ");
            scanf("%s", img_path);
            printf("Enter message to hide: ");
            getchar();
            fgets(msg, MAX_CHAR, stdin);
            msg[strlen(msg) - 1] = '\0'; // remove trailing newline character
            hide_message(msg, img_path);
            printf("Message hidden successfully!\n");
            break;
        case 2:
            printf("Enter path of image file: ");
            scanf("%s", img_path);
            printf("Enter path of output file: ");
            scanf("%s", msg_path);
            extract_message(msg_path, img_path);
            printf("Message extracted successfully!\n");
            break;
        case 3:
            printf("Exiting program. Goodbye!\n");
            return 0;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }
}
//FormAI DATASET v1.0 Category: Image Steganography ; Style: medieval
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

void encode(char *image, char *message)
{
    FILE *fp_image, *fp_encoded;
    long int length, file_size, i, j, pos = 0;
    char outfile[100];
    char *buffer, *secretmsg, c, mask = 1;

    fp_image = fopen(image, "rb");
    if(fp_image == NULL)
    {
        printf("Error: Unable to open image file!");
        exit(1);
    }

    fseek(fp_image, 0L, SEEK_END);
    file_size = ftell(fp_image);
    fseek(fp_image, 0L, SEEK_SET);

    buffer = (char *)malloc(file_size+1);
    if(buffer == NULL)
    {
        printf("Error: Out of memory!");
        fclose(fp_image);
        exit(1);
    }

    length = fread(buffer, sizeof(char), file_size, fp_image);
    fclose(fp_image);

    secretmsg = (char *)malloc(sizeof(char) * strlen(message));
    if(secretmsg == NULL)
    {
        printf("Error: Out of memory!");
        free(buffer);
        exit(1);
    }

    strcpy(secretmsg, message);
    strcat(secretmsg, "\n");

    printf("Enter the output file name: ");
    scanf("%s", outfile);

    fp_encoded = fopen(outfile, "wb+");
    if(fp_encoded == NULL)
    {
        printf("Error: Unable to create output file!");
        free(buffer);
        free(secretmsg);
        exit(1);
    }

    fwrite(buffer, sizeof(char), file_size, fp_encoded);

    for(i = 0; secretmsg[i] != '\0'; i++)
    {
        for(j = 0; j < 8; j++)
        {
            c = secretmsg[i];
            if(c & mask)
            {
                if(pos >= file_size)
                {
                    printf("Error: Image not large enough to encode message!");
                    free(buffer);
                    free(secretmsg);
                    fclose(fp_encoded);
                    exit(1);
                }
                buffer[pos++] |= 1;
            }
            else
            {
                buffer[pos++] &= ~1;
            }
            mask <<= 1;
        }
        mask = 1;
    }

    fwrite(buffer, sizeof(char), file_size, fp_encoded);

    free(buffer);
    free(secretmsg);

    printf("Encoded!");
    fclose(fp_encoded);

    return;
}

void decode(char *image)
{
    FILE *fp_image;
    long int length, file_size, i, j, pos = 0;
    char *buffer, msg[100] = {'\0'}, c, mask = 1;

    fp_image = fopen(image, "rb");
    if(fp_image == NULL)
    {
        printf("Error: Unable to open image file!");
        exit(1);
    }

    fseek(fp_image, 0L, SEEK_END);
    file_size = ftell(fp_image);
    fseek(fp_image, 0L, SEEK_SET);

    buffer = (char *)malloc(file_size+1);
    if(buffer == NULL)
    {
        printf("Error: Out of memory!");
        fclose(fp_image);
        exit(1);
    }

    length = fread(buffer, sizeof(char), file_size, fp_image);

    for(i = 0; pos < file_size; i++)
    {
        for(j = 0; j < 8; j++)
        {
            c = buffer[pos++];
            if(c & 1)
            {
                msg[i] |= mask;
            }
            mask <<= 1;
        }
        mask = 1;
    }

    printf("%s", msg);
    fclose(fp_image);
    free(buffer);

    return;
}

int main()
{
    char image[100], message[100];
    int choice;

    printf("Welcome to Medieval Image Steganography!\n");
    printf("===========================================\n");

    while(1)
    {
        printf("\nMenu:\n");
        printf("1. Encode Message in Image\n");
        printf("2. Decode Message from Image\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: printf("\nEnter the image file name: ");
                    scanf("%s", image);
                    printf("Enter the message: ");
                    scanf(" %[^\n]", message);
                    encode(image, message);
                    break;
      
            case 2: printf("\nEnter the image file name: ");
                    scanf("%s", image);
                    printf("The decoded message is: ");
                    decode(image);
                    printf("\n");
                    break;

            case 3: printf("Exiting!");
                    exit(0);

            default: printf("Invalid Choice!");
        }
    }
    
    return 0;
}
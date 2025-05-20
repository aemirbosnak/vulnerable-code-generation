//FormAI DATASET v1.0 Category: Image Steganography ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>

int main()
{
    char file_name[25], secret_msg[1000], ch, bit;
    FILE *fptr, *fptr2;
    int i = 0, j = 0;

    printf("Enter the name of the file to be hidden (along with extension): ");
    scanf("%s", file_name);

    // Opening the file to be hidden
    fptr = fopen(file_name, "r");
    if(fptr == NULL)
    {
        printf("Error: Failed to open the file!\n");
        exit(1);
    }

    // Copying the contents of the file to an array
    while((ch = fgetc(fptr)) != EOF)
    {
        secret_msg[i] = ch;
        i++;
    }

    // Closing the file
    fclose(fptr);

    printf("Enter the name of the image file (along with extension): ");
    scanf("%s", file_name);

    // Opening the image file
    fptr = fopen(file_name, "rb");
    if(fptr == NULL)
    {
        printf("Error: Failed to open the image file!\n");
        exit(1);
    }

    printf("Enter the name of the output image file (along with extension): ");
    scanf("%s", file_name);

    // Creating the output image file
    fptr2 = fopen(file_name, "wb");

    // Hiding the message in the image
    while((ch = fgetc(fptr)) != EOF)
    {
        bit = secret_msg[j];
        for(i = 7; i >= 0; i--)
        {
            if((bit >> i) & 1)
                ch |= 1 << i;
            else
                ch &= ~(1 << i);
        }
        j++;
        fputc(ch, fptr2);
    }

    // Closing the files
    fclose(fptr);
    fclose(fptr2);

    printf("Message hidden successfully!\n");

    return 0;
}
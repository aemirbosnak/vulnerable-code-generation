//FormAI DATASET v1.0 Category: Image Steganography ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MSG_SIZE 1000
#define MAX_IMAGE_SIZE 100000

// Function to convert decimal to binary
char *decimalToBinary(int decimal_num)
{
    static char binary_num[8];
    int remainder, quotient;
    int i = 0;

    quotient = decimal_num;

    while (quotient != 0)
    {
        binary_num[i++] = quotient % 2 + '0';
        quotient = quotient / 2;
    }

    // Prepend with 0s to ensure binary has 8 digits
    while (i < 8)
    {
        binary_num[i++] = '0';
    }

    // Reverse the binary string
    for (int j = 0, k = i - 1; j < k; j++, k--)
    {
        int temp = binary_num[j];
        binary_num[j] = binary_num[k];
        binary_num[k] = temp;
    }

    return binary_num;
}

// Function to encode message in image
void encode(char *image_data, char *msg)
{
    int msg_len = strlen(msg);

    // Convert message length to binary
    char *len_in_binary = decimalToBinary(msg_len);

    // Insert message length into image data
    for (int i = 0; i < 8; i++)
    {
        image_data[i] = len_in_binary[i];
    }

    // Encode message in image data
    for (int i = 8, j = 0; j < msg_len; i += 3, j++)
    {
        // Convert message character to binary
        char *msg_char_in_binary = decimalToBinary(msg[j]);

        // Insert each bit of message character into image data
        for (int k = 0; k < 8; k++)
        {
            image_data[i + k] = msg_char_in_binary[k];
        }
    }

    printf("Message encoded successfully in image.\n");
}

// Function to decode message from image
void decode(char *image_data)
{
    char len_in_binary[8];

    // Extract message length from image data
    for (int i = 0; i < 8; i++)
    {
        len_in_binary[i] = image_data[i];
    }

    // Convert message length from binary to decimal
    int msg_len = strtol(len_in_binary, NULL, 2);

    char msg[MSG_SIZE];

    // Extract message character by character from image data
    for (int i = 8, j = 0; j < msg_len; i += 3, j++)
    {
        char msg_char_in_binary[8];

        // Extract each bit of message character from image data
        for (int k = 0; k < 8; k++)
        {
            msg_char_in_binary[k] = image_data[i + k];
        }

        // Convert message character from binary to decimal
        int msg_char = strtol(msg_char_in_binary, NULL, 2);

        // Append message character to message string
        msg[j] = msg_char;
    }

    printf("Message decoded successfully from image.\n");
    printf("Message: %s\n", msg);
}

int main()
{
    char image_data[MAX_IMAGE_SIZE];
    char msg[MSG_SIZE];

    // Read image data from file
    FILE *fp = fopen("image.txt", "r");
    fscanf(fp, "%[^\n]", image_data);
    fclose(fp);

    // Get user input for message
    printf("Enter a message to encode in the image:\n");
    scanf("%[^\n]", msg);

    // Encode message in image
    encode(image_data, msg);

    // Get user input for decoding
    printf("Do you want to decode the message from the image? (y/n)\n");
    char response;
    scanf(" %c", &response);

    if (response == 'y')
    {
        // Decode message from image
        decode(image_data);
    }

    return 0;
}
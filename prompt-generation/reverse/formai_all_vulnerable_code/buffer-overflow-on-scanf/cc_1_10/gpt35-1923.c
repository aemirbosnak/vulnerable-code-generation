//FormAI DATASET v1.0 Category: Image Steganography ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 256
#define MAX_KEY_LEN 256
#define MAX_MSG_LEN 1024

// Function for hiding message in the image
void hide_message(char *input_image, char *output_image, char *key, char *message) {
    FILE *fin, *fout;
    unsigned char byte;
    int msg_len, key_len, i, j, k;

    // Open input image file in binary mode
    fin = fopen(input_image, "rb");
    if (!fin) {
        printf("Could not open input image file\n");
        return;
    }

    // Open output image file in binary mode
    fout = fopen(output_image, "wb");
    if (!fout) {
        printf("Could not open output image file\n");
        return;
    }

    // Get the length of message and key
    msg_len = strlen(message);
    key_len = strlen(key);

    // Write key length and message length to the output file
    fwrite(&key_len, sizeof(int), 1, fout);
    fwrite(&msg_len, sizeof(int), 1, fout);

    // Write key to the output file
    fwrite(key, sizeof(char), key_len, fout);

    // Loop through image byte by byte and hide the message
    i = 0;
    j = 0;
    k = 0;
    while (fread(&byte, sizeof(unsigned char), 1, fin) == 1) {
        // XOR the byte with the key
        byte ^= key[j];

        // If message is not over yet, hide the message in the byte
        if (i < msg_len) {
            byte = (byte & 0xFE) | ((message[i] >> k) & 0x01);

            k++;
            if (k == 8) {
                k = 0;
                i++;
            }
        }

        // Write the byte to the output file
        fwrite(&byte, sizeof(unsigned char), 1, fout);

        // Move to next key byte
        j++;
        if (j == key_len) {
            j = 0;
        }
    }

    // Close input and output files
    fclose(fin);
    fclose(fout);

    printf("Message hidden successfully\n");
}

// Function for retrieving message from the image
void retrieve_message(char *input_image, char *key, char *message) {
    FILE *fin;
    unsigned char byte;
    int msg_len, key_len, i, j, k;

    // Open input image file in binary mode
    fin = fopen(input_image, "rb");
    if (!fin) {
        printf("Could not open input image file\n");
        return;
    }

    // Read key length and message length from the input file
    fread(&key_len, sizeof(int), 1, fin);
    fread(&msg_len, sizeof(int), 1, fin);

    // Read key from the input file
    char *input_key = (char *) malloc(sizeof(char) * (key_len + 1));
    fread(input_key, sizeof(char), key_len, fin);
    input_key[key_len] = '\0';

    // If the key doesn't match, exit
    if (strcmp(key, input_key) != 0) {
        printf("Invalid key\n");
        free(input_key);
        return;
    }

    // Loop through image byte by byte and retrieve the message
    i = 0;
    j = 0;
    k = 0;
    while (fread(&byte, sizeof(unsigned char), 1, fin) == 1 && i < msg_len) {
        // XOR the byte with the key
        byte ^= key[j];

        // Retrieve the message from the byte
        message[i] |= ((byte & 0x01) << k);

        k++;
        if (k == 8) {
            k = 0;
            i++;
        }

        // Move to next key byte
        j++;
        if (j == key_len) {
            j = 0;
        }
    }

    // Null terminate message
    message[msg_len] = '\0';

    // Close input file
    fclose(fin);

    printf("Message retrieved successfully: %s\n", message);
}

int main() {
    char input_image[MAX_FILENAME_LEN];
    char output_image[MAX_FILENAME_LEN];
    char key[MAX_KEY_LEN];
    char message[MAX_MSG_LEN];
    int action;

    printf("Enter 1 to hide message, 2 to retrieve message: ");
    scanf("%d", &action);

    if (action == 1) {
        printf("Enter input image filename: ");
        scanf("%s", input_image);
        printf("Enter output image filename: ");
        scanf("%s", output_image);
        printf("Enter key: ");
        scanf("%s", key);
        printf("Enter message: ");
        scanf("%s", message);

        hide_message(input_image, output_image, key, message);
    }
    else if (action == 2) {
        printf("Enter input image filename: ");
        scanf("%s", input_image);
        printf("Enter key: ");
        scanf("%s", key);

        retrieve_message(input_image, key, message);
    }
    else {
        printf("Invalid action\n");
        return 1;
    }

    return 0;
}
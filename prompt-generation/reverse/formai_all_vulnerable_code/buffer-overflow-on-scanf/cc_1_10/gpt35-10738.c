//FormAI DATASET v1.0 Category: Image Steganography ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Enter the file name to hide message: ");
    char file_name[100];
    scanf("%s", file_name);
    FILE *fptr1, *fptr2;

    fptr1 = fopen(file_name, "rb");
    if (fptr1 == NULL) {
        printf("Cannot open file %s \n", file_name);
        exit(0);
    }

    printf("Enter the file name to store message: ");
    char message_file[100];
    scanf("%s", message_file);

    fptr2 = fopen(message_file, "wb");
    if (fptr2 == NULL) {
        printf("Cannot open file %s \n", message_file);
        exit(0);
    }

    printf("Enter the message to hide: ");
    char message[1000];
    scanf("%s", message);

    int c;

    while ((c = fgetc(fptr1)) != EOF) {
        for (int i = 0; i < strlen(message); i++) {
            int ascii_val = (int) message[i];
            int shift_val = 0;
            if (i % 2 == 0) {
                shift_val = ascii_val >> 1;
            } else {
                shift_val = ascii_val << 1;
            }
            int new_val = c + shift_val;
            fputc(new_val, fptr2);
        }
    }

    fclose(fptr1);
    fclose(fptr2);

    printf("Message hidden successfully!\n");

    return 0;
}
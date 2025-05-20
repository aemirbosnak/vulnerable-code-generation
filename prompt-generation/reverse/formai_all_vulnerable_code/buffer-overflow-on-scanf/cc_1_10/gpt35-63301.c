//FormAI DATASET v1.0 Category: File handling ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

void encode_text(FILE *input_file, FILE *output_file, char* key) {

    int key_length = strlen(key);
    char current_key;
    int i = 0;

    while (!feof(input_file)) {
        char current_char = fgetc(input_file);

        if (i >= key_length) {
            i = 0;
        }

        current_key = key[i];

        int encoded_char = current_char ^ current_key;

        fputc(encoded_char, output_file);

        i++;
    }

    fclose(input_file);
    fclose(output_file);
}


void decode_text(FILE *encoded_file, FILE *decrypted_file, char* key) {
    encode_text(encoded_file, decrypted_file, key);
}


void print_menu() {
    printf("=== CODE PUZZLE ===\n");
    printf("1. Encode Text\n");
    printf("2. Decode Text\n");
    printf("3. Exit\n");

    printf("Enter input: ");
}


int main() {

    FILE *encoded_file;
    FILE *decrypted_file;

    char encoded_file_path[100];
    char decrypted_file_path[100];
    char key[100];

    int user_choice = 0;

    do {
        print_menu();

        scanf("%d", &user_choice);

        switch (user_choice) {
            case 1:
                printf("Enter the path of the file to be encoded: ");
                scanf("%s", encoded_file_path);

                encoded_file = fopen(encoded_file_path, "r");

                if (encoded_file == NULL) {
                    printf("Could not open file!");
                    break;
                }

                printf("Enter the path of the output file: ");
                scanf("%s", decrypted_file_path);

                decrypted_file = fopen(decrypted_file_path, "w");

                printf("Enter the key to be used: ");
                scanf("%s", key);

                encode_text(encoded_file, decrypted_file, key);

                printf("File encoded!");
                break;

            case 2:
                printf("Enter the path of the encoded file: ");
                scanf("%s", encoded_file_path);

                encoded_file = fopen(encoded_file_path, "r");

                if (encoded_file == NULL) {
                    printf("Could not open file!");
                    break;
                }

                printf("Enter the path of the output file: ");
                scanf("%s", decrypted_file_path);

                decrypted_file = fopen(decrypted_file_path, "w");

                printf("Enter the key to be used: ");
                scanf("%s", key);

                decode_text(encoded_file, decrypted_file, key);

                printf("File decoded!");
                break;

            case 3:
                printf("Exiting program...");
                return 0;

            default:
                printf("Invalid choice! Try again.");
        }
    } while (user_choice != 3);

    return 0;
}
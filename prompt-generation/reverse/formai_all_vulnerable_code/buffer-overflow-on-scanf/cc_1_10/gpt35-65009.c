//FormAI DATASET v1.0 Category: File Encyptor ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>

// function to encrypt the file
void encrypt_file(char* file_name, char* key) {
    FILE* fileptr;
    int key_index = 0;
    char ch, new_ch;

    // open the file in read mode
    fileptr = fopen(file_name, "r");

    // check if file exists and readable
    if (fileptr == NULL) {
        printf("Error: Could not open file %s for reading.\n", file_name);
        exit(1);
    }

    // create a temporary file to store the encrypted data
    FILE* temp_file_ptr = fopen("temp.txt", "w");

    // read the file character by character and encrypt it using key
    while ((ch = fgetc(fileptr)) != EOF) {
        new_ch = ch ^ key[key_index];
        fputc(new_ch, temp_file_ptr);

        // update key index
        key_index++;
        if (key[key_index] == '\0') {
            key_index = 0;
        }
    }

    // close the files
    fclose(fileptr);
    fclose(temp_file_ptr);

    // remove the original file and rename the temporary file to original file name
    remove(file_name);
    rename("temp.txt", file_name);
}

int main() {
    char file_name[50], key[50];

    // get input from user
    printf("Enter the file name to encrypt: ");
    scanf("%s", file_name);
    printf("Enter the key for encryption: ");
    scanf("%s", key);

    // call the function to encrypt the file
    encrypt_file(file_name, key);

    printf("File %s encrypted successfully using key %s.\n", file_name, key);
    return 0;
}
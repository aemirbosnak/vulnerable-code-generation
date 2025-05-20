//Falcon-180B DATASET v1.0 Category: Password management ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define struct for password data
typedef struct {
    char username[50];
    char password[50];
} PasswordData;

// Function to create a new password data
PasswordData* createPasswordData(char* username, char* password) {
    PasswordData* newData = (PasswordData*)malloc(sizeof(PasswordData));
    strcpy(newData->username, username);
    strcpy(newData->password, password);
    return newData;
}

// Function to store password data in a file
void storePasswords(PasswordData* data, FILE* file) {
    fwrite(data, sizeof(PasswordData), 1, file);
}

// Function to read password data from a file
PasswordData* readPasswordData(FILE* file) {
    PasswordData* data = (PasswordData*)malloc(sizeof(PasswordData));
    fread(data, sizeof(PasswordData), 1, file);
    return data;
}

// Function to display a list of stored passwords
void displayPasswords(PasswordData* data, int count) {
    printf("List of stored passwords:\n");
    for(int i=0; i<count; i++) {
        printf("Username: %s\nPassword: %s\n", data[i].username, data[i].password);
    }
}

// Main function to manage passwords
int main() {
    FILE* passwordFile;
    PasswordData* data;
    int count=0;

    // Open the password file
    passwordFile = fopen("passwords.txt", "wb");
    if(passwordFile == NULL) {
        printf("Error opening password file.\n");
        return 1;
    }

    // Create initial password data
    data = createPasswordData("user1", "password1");
    storePasswords(data, passwordFile);
    count++;

    // Read stored password data
    rewind(passwordFile);
    data = readPasswordData(passwordFile);
    while(data!= NULL) {
        displayPasswords(data, count);
        data = readPasswordData(passwordFile);
        count++;
    }

    // Close the password file
    fclose(passwordFile);

    return 0;
}
//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to add a new user to the mailing list
void addUser(char* userName, char* email, char* mailingList) {
    int listSize = 0;
    
    // Check if the mailing list already exists
    FILE* fp = fopen(mailingList, "r");
    if (fp == NULL) {
        fclose(fp);
        printf("Mailing list does not exist. Creating a new one...\n");
        fp = fopen(mailingList, "w");
        if (fp == NULL) {
            printf("Error creating mailing list.\n");
            return;
        }
    } else {
        // Read the size of the mailing list
        fscanf(fp, "%d", &listSize);
    }
    
    // Append the new user to the mailing list
    char* newLine = (char*)malloc((listSize + 1) * sizeof(char));
    sprintf(newLine, "%s %s\n", userName, email);
    
    // Write the new line to the mailing list
    fwrite(newLine, strlen(newLine) + 1, 1, fp);
    
    // Close the file
    fclose(fp);
}

// Function to remove a user from the mailing list
void removeUser(char* userName, char* mailingList) {
    int listSize = 0;
    
    // Check if the mailing list already exists
    FILE* fp = fopen(mailingList, "r");
    if (fp == NULL) {
        fclose(fp);
        printf("Mailing list does not exist.\n");
        return;
    } else {
        // Read the size of the mailing list
        fscanf(fp, "%d", &listSize);
    }
    
    // Find the index of the user to remove
    int index = -1;
    for (int i = 0; i < listSize; i++) {
        if (strcmp(mailingList[i], userName) == 0) {
            index = i;
            break;
        }
    }
    
    // Remove the user from the mailing list
    if (index!= -1) {
        int newSize = listSize - 1;
        char* newMailingList = (char*)malloc((newSize * sizeof(char)) + 1);
        for (int i = 0; i < newSize; i++) {
            newMailingList[i] = mailingList[i];
        }
        newMailingList[newSize] = '\0';
        
        // Write the new mailing list to the file
        fp = fopen(mailingList, "w");
        if (fp == NULL) {
            printf("Error writing to mailing list.\n");
            return;
        }
        fwrite(newMailingList, strlen(newMailingList) + 1, 1, fp);
        fclose(fp);
    } else {
        printf("User not found in the mailing list.\n");
    }
}

int main() {
    // Add a new user to the mailing list
    addUser("John Doe", "johndoe@example.com", "mailinglist.txt");
    
    // Remove a user from the mailing list
    removeUser("John Doe", "mailinglist.txt");
    
    return 0;
}
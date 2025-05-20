//FormAI DATASET v1.0 Category: Password management ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char username[32];
    char password[32];
    char website[64];
} Credential;

int countLines(FILE *fp) {
    int count = 0;
    char ch;
    while(!feof(fp)) {
        ch = fgetc(fp);
        if(ch == '\n') {
            count++;
        }
    }
    rewind(fp);
    return count;
}

int searchCredential(Credential *credentials, int len, char *website) {
    for(int i = 0; i < len; i++) {
        if(!strcmp(credentials[i].website, website)) {
            return i;
        }
    }
    return -1;
}

void checkPasswordStrength(char *password) {
    int upperCaseCount = 0, lowerCaseCount = 0, digitCount = 0;
    for(int i = 0; i < strlen(password); i++) {
        if(isupper(password[i])) {
            upperCaseCount++;
        } else if(islower(password[i])) {
            lowerCaseCount++;
        } else if(isdigit(password[i])) {
            digitCount++;
        }
    }
    if(upperCaseCount == 0 || lowerCaseCount == 0 || digitCount == 0) {
        printf("Warning: Password is weak! It should contain at least one uppercase, one lowercase and one digit.\n");
    }
}

void addCredential(Credential *credentials, int *len) {
    char username[32], password[32], website[64];
    int pos;
    do {
        printf("Enter the website name: ");
        scanf("%s", website);
        pos = searchCredential(credentials, *len, website);
        if(pos >= 0) {
            printf("Credential for this website already exists!\n");
        }
    } while(pos >= 0);
    printf("Enter the username: ");
    scanf("%s", username);
    printf("Enter the password: ");
    scanf("%s", password);
    checkPasswordStrength(password);
    strcpy(credentials[*len].username, username);
    strcpy(credentials[*len].password, password);
    strcpy(credentials[*len].website, website);
    (*len)++;
    printf("Credential added successfully!\n");
}

void updateCredential(Credential *credentials, int len) {
    char website[64];
    int pos;
    printf("Enter the website name for which you want to update the credential: ");
    scanf("%s", website);
    pos = searchCredential(credentials, len, website);
    if(pos < 0) {
        printf("Credential for this website does not exist!\n");
    } else {
        printf("Enter the new username: ");
        scanf("%s", credentials[pos].username);
        printf("Enter the new password: ");
        scanf("%s", credentials[pos].password);
        checkPasswordStrength(credentials[pos].password);
        printf("Credential updated successfully!\n");
    }
}

void deleteCredential(Credential *credentials, int *len) {
    char website[64];
    int pos;
    printf("Enter the website name for which you want to delete the credential: ");
    scanf("%s", website);
    pos = searchCredential(credentials, *len, website);
    if(pos < 0) {
        printf("Credential for this website does not exist!\n");
    } else {
        for(int i = pos; i < *len - 1; i++) {
            credentials[i] = credentials[i+1];
        }
        (*len)--;
        printf("Credential deleted successfully!\n");
    }
}

void displayCredentials(Credential *credentials, int len) {
    if(len == 0) {
        printf("No credentials found!\n");
    } else {
        printf("Website Name\tUsername\tPassword\n");
        for(int i = 0; i < len; i++) {
            printf("%s\t\t%s\t\t%s\n", credentials[i].website, credentials[i].username, credentials[i].password);
        }
    }
}

int main() {
    FILE *fp = fopen("credentials.txt", "r");
    Credential credentials[100];
    int len = countLines(fp);
    for(int i = 0; i < len; i++) {
        fscanf(fp, "%s %s %s", credentials[i].website, credentials[i].username, credentials[i].password);
    }
    fclose(fp);
    char choice;
    do {
        printf("\nPassword Management System\n");
        printf("--------------------------\n");
        printf("1. Add a Credential\n");
        printf("2. Update a Credential\n");
        printf("3. Delete a Credential\n");
        printf("4. Display all Credentials\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch(choice) {
            case '1':
                addCredential(credentials, &len);
                break;
            case '2':
                updateCredential(credentials, len);
                break;
            case '3':
                deleteCredential(credentials, &len);
                break;
            case '4':
                displayCredentials(credentials, len);
                break;
            case '5':
                fp = fopen("credentials.txt", "w");
                for(int i = 0; i < len; i++) {
                    fprintf(fp, "%s %s %s\n", credentials[i].website, credentials[i].username, credentials[i].password);
                }
                fclose(fp);
                printf("Thank you for using the Password Management System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a choice between 1 and 5.\n");
        }
    } while(choice != '5');
    return 0;
}
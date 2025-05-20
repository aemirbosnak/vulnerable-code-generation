//Falcon-180B DATASET v1.0 Category: Password management ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

#define SIZE 1000 // maximum number of passwords
#define MIN_LENGTH 8 // minimum length of password
#define MAX_LENGTH 20 // maximum length of password

typedef struct {
    char password[MAX_LENGTH]; // password string
    int length; // length of password
    time_t creation_time; // time of password creation
} Password;

Password passwords[SIZE]; // array to store passwords
int num_passwords = 0; // number of passwords currently stored

void generate_password(int length) {
    char password[MAX_LENGTH];
    int i;
    for (i = 0; i < length; i++) {
        password[i] = rand() % 10 + '0'; // generate a random number between 0 and 9
    }
    password[i] = '\0'; // terminate the string
    strcpy(passwords[num_passwords].password, password); // store the generated password
    passwords[num_passwords].length = length; // store the length of the generated password
    passwords[num_passwords].creation_time = time(NULL); // store the time of password creation
    num_passwords++; // increment the number of passwords stored
}

void display_passwords() {
    int i;
    for (i = 0; i < num_passwords; i++) {
        printf("Password %d: %s\n", i+1, passwords[i].password);
        printf("Length: %d\n", passwords[i].length);
        printf("Creation time: %s\n", ctime(&passwords[i].creation_time));
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // initialize the random number generator
    int choice;
    do {
        printf("1. Generate a new password\n");
        printf("2. Display all passwords\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the length of the password: ");
                int length;
                scanf("%d", &length);
                if (length < MIN_LENGTH || length > MAX_LENGTH) {
                    printf("Invalid password length.\n");
                } else {
                    generate_password(length);
                    printf("Password generated successfully.\n");
                }
                break;
            case 2:
                display_passwords();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);
    return 0;
}
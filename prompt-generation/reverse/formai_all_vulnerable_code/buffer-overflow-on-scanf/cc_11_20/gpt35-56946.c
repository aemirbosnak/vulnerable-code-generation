//FormAI DATASET v1.0 Category: Data validation ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int main(){
    char name[20], password[20], email[30], gender[10], contact[15];
    int age;
    
    // Input name
    printf("Enter your name: ");
    fgets(name, 20, stdin);
    name[strcspn(name, "\n")] = 0; // remove newline character from name
    
    // Input password
    printf("Enter your password: ");
    fgets(password, 20, stdin);
    password[strcspn(password, "\n")] = 0; // remove newline character from password
    
    // Input email
    printf("Enter your email: ");
    fgets(email, 30, stdin);
    email[strcspn(email, "\n")] = 0; // remove newline character from email
    
    // Input age
    printf("Enter your age: ");
    scanf("%d", &age);
    getchar(); // to consume the newline character left in the stdin
    
    // Input gender
    printf("Enter your gender (Male/Female/Other): ");
    fgets(gender, 10, stdin);
    gender[strcspn(gender, "\n")] = 0; // remove newline character from gender
    
    // Input contact
    printf("Enter your contact number: ");
    fgets(contact, 15, stdin);
    contact[strcspn(contact, "\n")] = 0; // remove newline character from contact
    
    // Data validation
    int valid = 1; // assume all data is valid
    if(strlen(name) < 3) {
        printf("Name must be atleast 3 characters!\n");
        valid = 0;
    }
    if(strlen(password) < 8) {
        printf("Password must be atleast 8 characters!\n");
        valid = 0;
    }
    if(!isalpha(name[0])) {
        printf("First character of name must be an alphabet!\n");
        valid = 0;
    }
    if(age < 18 || age > 60) {
        printf("Age must be between 18 and 60!\n");
        valid = 0;
    }
    if(strcmp(gender, "Male") != 0 && strcmp(gender, "Female") != 0 && strcmp(gender, "Other") != 0) {
        printf("Gender must be one of Male/Female/Other!\n");
        valid = 0;
    }
    int len = strlen(contact);
    if(len < 10 || len > 12) {
        printf("Contact number must be between 10 and 12 digits!\n");
        valid = 0;
    }
    for(int i=0; i<len; i++) {
        if(!isdigit(contact[i])) {
            printf("Contact number can contain only digits!\n");
            valid = 0;
            break;
        }
    }
    
    if(valid == 0) {
        printf("Data Validation Failed!\n");
    } else {
        printf("Data Validation Successful!\n");
    }
    
    return 0;
}
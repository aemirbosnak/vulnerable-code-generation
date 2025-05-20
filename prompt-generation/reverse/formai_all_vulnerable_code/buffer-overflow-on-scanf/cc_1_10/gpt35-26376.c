//FormAI DATASET v1.0 Category: Password management ; Style: safe
#include<stdio.h>
#include<string.h>

#define MAX_PASSWORDS 10

void clearBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int password_strength(char* password){
    int length = strlen(password);
    int uppercase_count = 0;
    int lowercase_count = 0;
    int number_count = 0;
    int special_count = 0;
    
    for(int i=0; i<length; i++){
        char ch = password[i];
        if(ch >= 'A' && ch <= 'Z'){
            uppercase_count++;
        }
        else if(ch >= 'a' && ch <= 'z'){
            lowercase_count++;
        }
        else if(ch >= '0' && ch <= '9'){
            number_count++;
        }
        else{
            special_count++;
        }
    }
    
    if(length < 8){
        return 1;
    }
    else if(uppercase_count==0 || lowercase_count==0 || number_count==0 || special_count==0){
        return 2;
    }
    else{
        return 3;
    }
}

void add_password(char passwords[MAX_PASSWORDS][50], int* count){
    char new_password[50];
    int strength;
    
    printf("Enter new password: ");
    scanf("%s", new_password);
    clearBuffer();
    
    strength = password_strength(new_password);
    
    if(strength == 1){
        printf("Password is too weak\n");
        return;
    }
    else if(strength == 2){
        printf("Password is moderately strong\n");
    }
    else{
        printf("Password is very strong\n");
    }
    
    if(*count < MAX_PASSWORDS){
        strcpy(passwords[*count], new_password);
        *count = *count + 1;
        printf("Password added successfully\n");
    }
    else{
        printf("Maximum password capacity reached\n");
    }
}

void view_passwords(char passwords[MAX_PASSWORDS][50], int count){
    if(count == 0){
        printf("No passwords stored\n");
    }
    else{
        printf("Stored passwords:\n");
        for(int i=0; i<count; i++){
            printf("%s\n", passwords[i]);
        }
    }
}

void delete_password(char passwords[MAX_PASSWORDS][50], int* count){
    char password_to_delete[50];
    int found = 0;
    
    printf("Enter password to delete: ");
    scanf("%s", password_to_delete);
    clearBuffer();
    
    for(int i=0; i<*count; i++){
        if(strcmp(passwords[i], password_to_delete) == 0){
            for(int j=i; j<*count-1; j++){
                strcpy(passwords[j], passwords[j+1]);
            }
            *count = *count - 1;
            found = 1;
            printf("Password deleted successfully\n");
            break;
        }
    }
    
    if(!found){
        printf("Password not found\n");
    }
}

int main(){
    char passwords[MAX_PASSWORDS][50];
    int count = 0;
    int choice;
    
    do{
        printf("\n----Password Manager----\n");
        printf("1. Add password\n");
        printf("2. View passwords\n");
        printf("3. Delete password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();
        
        switch(choice){
            case 1:
                add_password(passwords, &count);
                break;
            case 2:
                view_passwords(passwords, count);
                break;
            case 3:
                delete_password(passwords, &count);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
        
    }while(choice != 4);
    
    return 0;
}
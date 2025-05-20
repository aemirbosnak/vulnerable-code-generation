//FormAI DATASET v1.0 Category: Database simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    char email[50];
} User;

int getUserCount() {
    FILE *fp;
    int count=0;

    fp = fopen("users.dat","rb");
    if(fp == NULL) {
        return 0;
    }

    fseek(fp,0,SEEK_END);
    count = ftell(fp) / sizeof(User);

    fclose(fp);

    return count;
}

void addUser() {
    FILE *fp;
    User user;
    char name[50];
    char email[50];

    printf("Enter name: ");
    scanf("%s",name);
    strcpy(user.name,name);

    printf("Enter email: ");
    scanf("%s",email);
    strcpy(user.email,email);

    int count = getUserCount();

    user.id = count + 1;

    fp = fopen("users.dat","ab");
    if(fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    fwrite(&user,sizeof(User),1,fp);

    fclose(fp);

    printf("\nUser added successfully!\n");
}

void removeUser() {
    FILE *fp;
    int id, found=0;

    printf("Enter ID of user to remove: ");
    scanf("%d",&id);

    User user;

    fp = fopen("users.dat","rb");
    if(fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    fseek(fp,0,SEEK_SET);

    while(fread(&user,sizeof(User),1,fp) != 0) {
        if(user.id == id) {
            found = 1;
            break;
        }
    }

    if(found == 0) {
        printf("User with ID %d not found\n", id);
        fclose(fp);
        return;
    }

    fseek(fp,-sizeof(User),SEEK_CUR);

    User blankUser = {0,"",""};

    fwrite(&blankUser,sizeof(User),1,fp);

    fclose(fp);

    printf("\nUser removed successfully!\n");
}

void displayUsers() {
    FILE *fp;
    User user;

    fp = fopen("users.dat","rb");
    if(fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    printf("\nUser ID\tName\tEmail\n");
    printf("------------------------------------\n");

    while(fread(&user,sizeof(User),1,fp) != 0) {
        if(user.id != 0) {
            printf("%d\t%s\t%s\n",user.id,user.name,user.email);
        }
    }

    fclose(fp);
}

int main() {
    int choice;

    printf("Welcome to User Database Simulation!\n");

    while(1) {
        printf("\n1. Add User\n2. Remove User\n3. Display Users\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                addUser();
                break;
            case 2:
                removeUser();
                break;
            case 3:
                displayUsers();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
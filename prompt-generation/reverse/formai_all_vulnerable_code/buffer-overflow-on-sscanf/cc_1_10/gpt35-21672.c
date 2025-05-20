//FormAI DATASET v1.0 Category: Database querying ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    char email[100];
} User;

void addUser(User user) { // function to add a user to the database
    FILE* fp;
    fp = fopen("database.txt","a");
    fprintf(fp,"%d %s %s\n",user.id,user.name,user.email);
    fclose(fp);
}

User* getUsers(int* count, char* name) { // function to get all users from the database with a specific name
    FILE* fp;
    char line[150];
    User* users = malloc(100 * sizeof(User));
    fp = fopen("database.txt","r");
    int i = 0;
    while (fgets(line,150,fp) != NULL) {
        User user;
        sscanf(line,"%d %s %s",&user.id,user.name,user.email);
        if (!strcmp(user.name,name)) {
            users[i] = user; 
            i++;
        }
    }
    *count = i;
    fclose(fp);
    return users;
}

User getUser(int id) { // function to get a user from the database with a specific id
    FILE* fp;
    char line[150];
    User user;
    fp = fopen("database.txt","r");
    while (fgets(line,150,fp) != NULL) {
        sscanf(line,"%d %s %s",&user.id,user.name,user.email);
        if (user.id == id) {
            fclose(fp);
            return user;
        }
    }
    fclose(fp);
    User invalid = {-1,"",""}; // return an invalid user (id = -1) if no user was found
    return invalid;
}

int deleteUser(int id) { // function to delete a user from the database with a specific id
    FILE* fp1, *fp2;
    char line[150];
    User user;
    fp1 = fopen("database.txt","r");
    fp2 = fopen("temp.txt","w");
    int deleted = 0;
    while (fgets(line,150,fp1) != NULL) {
        sscanf(line,"%d %s %s",&user.id,user.name,user.email);
        if (user.id != id) {
            fprintf(fp2,"%d %s %s\n",user.id,user.name,user.email);
        }
        else {
            deleted = 1;
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove("database.txt");
    rename("temp.txt","database.txt");
    if (deleted) {
        return 1;
    }
    else {
        return 0;
    }
}

int updateUser(User user) { // function to update a user in the database with a specific id
    FILE* fp1, *fp2;
    char line[150];
    User current;
    fp1 = fopen("database.txt","r");
    fp2 = fopen("temp.txt","w");
    int updated = 0;
    while (fgets(line,150,fp1) != NULL) {
        sscanf(line,"%d %s %s",&current.id,current.name,current.email);
        if (current.id != user.id) {
            fprintf(fp2,"%d %s %s\n",current.id,current.name,current.email);
        }
        else {
            fprintf(fp2,"%d %s %s\n",user.id,user.name,user.email);
            updated = 1;
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove("database.txt");
    rename("temp.txt","database.txt");
    if (updated) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    User u1 = {1,"John Smith","john.smith@example.com"};
    User u2 = {2,"Jane Doe","jane.doe@example.com"};
    User u3 = {3,"John Doe","john.doe@example.com"};
    addUser(u1);
    addUser(u2);
    addUser(u3);
    User u4 = {4,"Jane Smith","jane.smith@example.com"};
    addUser(u4);
    int count;
    User* users = getUsers(&count,"John");
    printf("Users with name John:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Email: %s\n",users[i].id,users[i].name,users[i].email);
    }
    User u5 = getUser(2);
    printf("User with ID 2:\n");
    printf("ID: %d, Name: %s, Email: %s\n",u5.id,u5.name,u5.email);
    int deleted = deleteUser(3);
    if (deleted) {
        printf("User with ID 3 deleted successfully!\n");
    }
    else {
        printf("User with ID 3 not found.\n");
    }
    User u6 = {2,"Jane Smith","jane.smith@example.com"};
    int updated = updateUser(u6);
    if (updated) {
        printf("User with ID 2 updated successfully!\n");
    }
    else {
        printf("User with ID 2 not found.\n");
    }
    return 0;
}
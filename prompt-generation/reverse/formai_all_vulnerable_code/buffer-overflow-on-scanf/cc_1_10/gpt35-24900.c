//FormAI DATASET v1.0 Category: Mailing list manager ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct mailing_list {
    char name[50];
    char email[50];
    int age;
};

void add_to_mailing_list(struct mailing_list ml[], int* size) {
    printf("Enter name: ");
    scanf("%s", ml[*size].name);
    printf("Enter email: ");
    scanf("%s", ml[*size].email);
    printf("Enter age: ");
    scanf("%d", &ml[*size].age);
    (*size)++;
    printf("Added to mailing list successfully.\n");
}

void display_mailing_list(struct mailing_list ml[], int size) {
    printf("Name\t\tEmail\t\t\tAge\n");
    for(int i=0;i<size;i++) {
        printf("%s\t\t%s\t\t\t%d\n", ml[i].name, ml[i].email, ml[i].age);
    }
}

void save_mailing_list(struct mailing_list ml[], int size) {
    FILE *fp;
    fp = fopen("mailing_list.dat", "wb");
    fwrite(ml, sizeof(struct mailing_list), size, fp);
    fclose(fp);
    printf("Mailing list saved successfully.\n");
}

void load_mailing_list(struct mailing_list ml[], int* size) {
    FILE *fp;
    fp = fopen("mailing_list.dat", "rb");
    if(fp==NULL) {
        printf("No mailing list found.\n");
        return;
    }
    int n = fread(ml, sizeof(struct mailing_list), 100, fp);
    *size = n;
    fclose(fp);
    printf("Mailing list loaded successfully.\n");
}

int main() {
    struct mailing_list ml[100];
    int size = 0;
    
    printf("Welcome to Mailing List Manager 3000!\n");
    while(1) {
        printf("\n1. Add person to mailing list\n2. Display mailing list\n3. Save mailing list\n4. Load mailing list\n5. Exit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_to_mailing_list(ml, &size);
                break;
            case 2:
                display_mailing_list(ml, size);
                break;
            case 3:
                save_mailing_list(ml, size);
                break;
            case 4:
                load_mailing_list(ml, &size);
                break;
            case 5:
                printf("Thank you for using Mailing List Manager 3000!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
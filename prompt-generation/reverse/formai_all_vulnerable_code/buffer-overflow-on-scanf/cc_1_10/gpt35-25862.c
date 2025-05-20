//FormAI DATASET v1.0 Category: File handling ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct dream {
    char name[20];
    int price;
};

void writeToDreamFile(FILE *fp) {
    struct dream d;
    printf("Enter the name of your dream: ");
    scanf("%s", d.name);
    printf("Enter the price of your dream: ");
    scanf("%d", &d.price);
    fwrite(&d, sizeof(struct dream), 1, fp);
    printf("Dream saved successfully!\n");
}

void readFromDreamFile(FILE *fp) {
    struct dream d;
    printf("List of Dreams:\n");
    while(fread(&d, sizeof(struct dream), 1, fp) == 1) {
        printf("Dream Name: %s\tDream Price: %d\n", d.name, d.price);
    }
}

int main() {
    FILE *fp;
    int choice;
    fp = fopen("dreams.txt", "ab+");
    printf("Welcome to the Dream World!\n");
    while(1) {
        printf("Enter your choice:\n1.Add Dream\n2.Display Dreams\n3.Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                writeToDreamFile(fp);
                break;
            case 2:
                readFromDreamFile(fp);
                break;
            case 3:
                printf("Exiting the Dream World!\n");
                fclose(fp);
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
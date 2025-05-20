//FormAI DATASET v1.0 Category: File handling ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>

struct student {
    int roll_no;
    char name[30];
    int score;
};

void add_student(FILE *fp) {
    struct student s;
    printf("\nEnter roll no: ");
    scanf("%d", &s.roll_no);
    printf("Enter name: ");
    scanf("%s", &s.name);
    printf("Enter score: ");
    scanf("%d", &s.score);
    fwrite(&s, sizeof(struct student), 1, fp);
}

void display_student(FILE *fp) {
    struct student s;
    printf("\nRoll No\tName\tScore\n");
    fread(&s, sizeof(struct student), 1, fp);
    while(!feof(fp)) {
        printf("%d\t%s\t%d\n", s.roll_no, s.name, s.score);
        fread(&s, sizeof(struct student), 1, fp);
    }
}

int main() {
    FILE *fp;
    fp = fopen("student.dat", "ab+");
    if(fp==NULL) {
        printf("Error opening file");
        exit(1);
    }
    int choice;
    do {
        printf("\n1. Add Student\n2. Display Students\n3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_student(fp);
                break;
            case 2:
                display_student(fp);
                break;
            case 3:
                printf("\nExiting..");
                break;
            default:
                printf("\nInvalid choice!");
        }
    } while(choice!=3);
    fclose(fp);
    return 0;
}
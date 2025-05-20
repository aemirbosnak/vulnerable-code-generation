//FormAI DATASET v1.0 Category: File handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int age;
};

int main() {
    int num, i;
    struct Student *s;

    printf("Enter the number of students: ");
    scanf("%d", &num);

    s = (struct Student*) malloc(num * sizeof(struct Student));

    // Getting information from user
    for(i = 0; i < num; i++) {
        printf("Enter name and age of student%d: ", i+1);
        scanf("%s %d", &(s+i)->name, &(s+i)->age);
    }

    // Writing to file
    FILE *fptr;
    fptr = fopen("students.txt", "w");
    if(fptr == NULL) {
        printf("Error in creating file!\n");
        exit(1);
    }

    for(i = 0; i < num; i++) {
        fprintf(fptr, "%s %d\n", (s+i)->name, (s+i)->age);
    }

    fclose(fptr);

    // Reading from file
    fptr = fopen("students.txt", "r");
    if(fptr == NULL) {
        printf("Error in opening file!\n");
        exit(1);
    }

    printf("\nThe contents of the file are:\n");
    char c = fgetc(fptr);
    while(c != EOF) {
        printf("%c", c);
        c = fgetc(fptr);
    }

    fclose(fptr);

    return 0;
}
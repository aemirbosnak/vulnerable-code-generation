//FormAI DATASET v1.0 Category: File handling ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

struct student {
    int id;
    char name[50];
    float grade;
};

void writeToFile(char *filename, struct student *s, int size) {
    FILE *fp = fopen(filename, "wb");
    if(fp == NULL) {
        printf("Error opening file.");
        exit(1);
    }
    for(int i=0; i<size; i++) {
        fwrite((s+i), sizeof(struct student), 1, fp);
    }
    fclose(fp);
}

void readFromFile(char *filename, int id) {
    FILE *fp = fopen(filename, "rb");
    if(fp == NULL) {
        printf("Error opening file.");
        exit(1);
    }
    struct student s;
    while(fread(&s, sizeof(struct student), 1, fp)) {
        if(s.id == id) {
            printf("ID: %d\nName: %s\nGrade: %.2f\n", s.id, s.name, s.grade);
            break;
        }
    }
    fclose(fp);
}

int main() {
    struct student students[3];
    for(int i=0; i<3; i++) {
        printf("Enter details for student %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &students[i].id);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Grade: ");
        scanf("%f", &students[i].grade);
    }
    // Writing students to file
    writeToFile("students.txt", students, 3);
    // Reading student details from file
    int searchId;
    printf("Enter ID to search: ");
    scanf("%d", &searchId);
    readFromFile("students.txt", searchId);
    return 0;
}
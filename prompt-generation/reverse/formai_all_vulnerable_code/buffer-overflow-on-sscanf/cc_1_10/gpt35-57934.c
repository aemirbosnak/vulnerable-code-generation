//FormAI DATASET v1.0 Category: File handling ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    char name[50];
    int age;
    char major[50];
};

void printStudentDetails(struct student s){
    printf("Name: %s\n", s.name);
    printf("Age: %d\n", s.age);
    printf("Major: %s\n", s.major);
}

int main(){
    struct student s1;
    printf("Enter Student Name: ");
    fgets(s1.name, sizeof(s1.name), stdin);
    s1.name[strcspn(s1.name, "\n")] = 0;

    printf("Enter Student Age: ");
    scanf("%d", &s1.age);

    printf("Enter Student Major: ");
    getchar();
    fgets(s1.major, sizeof(s1.major), stdin);
    s1.major[strcspn(s1.major, "\n")] = 0;

    FILE *fp = fopen("students.txt", "a");
    if(fp == NULL){
        printf("Error opening file\n");
        return 1;
    }

    fprintf(fp, "%s;%d;%s\n", s1.name, s1.age, s1.major);
    fclose(fp);

    char buf[1024];
    fp = fopen("students.txt", "r");
    if(fp == NULL){
        printf("Error opening file\n");
        return 1;
    }

    while(fgets(buf, 1024, fp) != NULL){
        struct student s2;
        char tmp[50];

        sscanf(buf, "%[^;];%d;%[^\n]", s2.name, &s2.age, s2.major);

        printf("\nStudent Details: \n");
        printStudentDetails(s2);
    }

    fclose(fp);

    return 0;
}
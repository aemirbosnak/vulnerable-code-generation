//Falcon-180B DATASET v1.0 Category: File handling ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct{
    char *name;
    int age;
    char *gender;
}Person;

Person *read_file(FILE *fp, int *count){
    char line[MAX_LINE_LENGTH];
    Person *people = (Person*)malloc(sizeof(Person));
    *count = 0;
    while(fgets(line, MAX_LINE_LENGTH, fp)!= NULL){
        char *token = strtok(line, ",");
        if(token!= NULL){
            people[*count].name = strdup(token);
            token = strtok(NULL, ",");
            people[*count].age = atoi(token);
            token = strtok(NULL, ",");
            people[*count].gender = strdup(token);
            (*count)++;
        }
    }
    return people;
}

void write_file(FILE *fp, Person *people, int count){
    fprintf(fp, "Name,Age,Gender\n");
    for(int i=0; i<count; i++){
        fprintf(fp, "%s,%d,%s\n", people[i].name, people[i].age, people[i].gender);
    }
}

void sort_people(Person *people, int count, int (*compare)(const void *, const void *)){
    qsort(people, count, sizeof(Person), compare);
}

int compare_age(const void *a, const void *b){
    Person *person_a = (Person*)a;
    Person *person_b = (Person*)b;
    return person_a->age - person_b->age;
}

int main(){
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");
    if(input_file == NULL || output_file == NULL){
        printf("Error opening file\n");
        exit(1);
    }
    int count = 0;
    Person *people = read_file(input_file, &count);
    sort_people(people, count, compare_age);
    write_file(output_file, people, count);
    fclose(input_file);
    fclose(output_file);
    free(people);
    return 0;
}
//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resume{
    char name[50];
    char email[50];
    char skills[500];
    struct resume *next;
};
typedef struct resume Resume;

Resume *head = NULL;

void parse(char *buffer, size_t size){
    char name[50], email[50], skills[500];
    sscanf(buffer, "%[^,],%[^,],%[^\n]s", name, email, skills);
    Resume *r = (Resume*) malloc(sizeof(Resume));
    strcpy(r->name, name);
    strcpy(r->email, email);
    strcpy(r->skills, skills);
    r->next = NULL;

    if(head == NULL){
        head = r;
    }else{
        Resume *curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = r;
    }
}

void printResumes(){
    Resume *curr = head;
    while(curr != NULL){
        printf("Name: %s\nEmail: %s\nSkills: %s\n", curr->name, curr->email, curr->skills);
        curr = curr->next;
    }
}

int main(){

    char buffer[1000];
    printf("Enter resumes: \n");
    while(fgets(buffer, 1000, stdin) != NULL){
        parse(buffer, strlen(buffer));
    }

    printf("Resumes parsed successfully!\n\n");

    printResumes();

    return 0;
}
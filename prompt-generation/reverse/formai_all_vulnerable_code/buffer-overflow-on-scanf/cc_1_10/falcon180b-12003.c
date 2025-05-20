//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RESUME_LENGTH 1000
#define MAX_KEYWORDS_LENGTH 100
#define MAX_KEYWORD_LENGTH 20
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    int num_keywords;
    char keywords[MAX_KEYWORDS_LENGTH][MAX_KEYWORD_LENGTH];
} resume;

void read_resume(resume* r) {
    char input[MAX_RESUME_LENGTH];
    fgets(input, MAX_RESUME_LENGTH, stdin);
    strcpy(r->name, input);
    printf("Name: %s\n", r->name);
    printf("Address: ");
    fgets(input, MAX_ADDRESS_LENGTH, stdin);
    strcpy(r->address, input);
    printf("Keywords: ");
    scanf("%d", &r->num_keywords);
    for (int i = 0; i < r->num_keywords; i++) {
        char keyword[MAX_KEYWORD_LENGTH];
        scanf("%s", keyword);
        strcpy(r->keywords[i], keyword);
    }
}

void write_resume(resume* r) {
    printf("Name: %s\n", r->name);
    printf("Address: %s\n", r->address);
    printf("Keywords:\n");
    for (int i = 0; i < r->num_keywords; i++) {
        printf("%s ", r->keywords[i]);
    }
    printf("\n");
}

int main() {
    resume r;
    read_resume(&r);
    write_resume(&r);
    return 0;
}
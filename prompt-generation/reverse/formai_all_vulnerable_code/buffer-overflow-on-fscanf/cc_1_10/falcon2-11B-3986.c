//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

struct Resume {
    char name[50];
    char phone[20];
    char email[50];
    char skills[100];
    char education[100];
};

int read_resume(char* filename, struct Resume* resume) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return 1;
    }

    fscanf(fp, "%s %s %s %s %s", resume->name, resume->phone, resume->email, resume->skills, resume->education);

    fclose(fp);

    return 0;
}

void* parse_resume(void* args) {
    struct Resume* resume = (struct Resume*) args;

    printf("Name: %s\n", resume->name);
    printf("Phone: %s\n", resume->phone);
    printf("Email: %s\n", resume->email);
    printf("Skills: %s\n", resume->skills);
    printf("Education: %s\n", resume->education);
}

int main() {
    pthread_t threads[10];
    struct Resume resume;
    char filename[] = "resume.txt";

    if (read_resume(filename, &resume)) {
        printf("Error reading resume file\n");
        return 1;
    }

    pthread_t thread[10];
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], &attr, parse_resume, (void*)&resume);
    }

    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_attr_destroy(&attr);

    return 0;
}
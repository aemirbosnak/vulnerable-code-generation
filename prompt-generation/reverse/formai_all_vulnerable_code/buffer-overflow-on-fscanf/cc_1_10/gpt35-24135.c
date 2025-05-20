//FormAI DATASET v1.0 Category: Log analysis ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct log {
    char date[20];
    char time[20];
    char message[200];
};

int count_logs(char *filename) {
    FILE *fp;
    fp = fopen(filename, "r");
    int count = 0;

    if(fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    while(!feof(fp)) {
        char ch = fgetc(fp);
        if(ch == '\n') {
            count++;
        }
    }

    fclose(fp);
    return count;
}

void read_logs(char *filename, struct log logs[], int n) {
    FILE *fp;
    fp = fopen(filename, "r");
    int i = 0;

    if(fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    while(!feof(fp)) {
        fscanf(fp, "%s %s %[^\n]", logs[i].date, logs[i].time, logs[i].message);
        i++;
    }

    fclose(fp);
}

void print_logs(struct log logs[], int n) {
    printf("Date\t\tTime\t\tMessage\n");
    for(int i=0; i<n; i++) {
        printf("%s\t%s\t%s\n", logs[i].date, logs[i].time, logs[i].message);
    }
    printf("\n");
}

void count_messages(struct log logs[], int n) {
    printf("Message Count\n");
    char messages[200][200];
    int counts[200];
    int count = 0;

    for(int i=0; i<n; i++) {
        int found = 0;
        for(int j=0; j<count; j++) {
            if(strcmp(messages[j], logs[i].message) == 0) {
                counts[j]++;
                found = 1;
                break;
            }
        }
        if(!found) {
            strcpy(messages[count], logs[i].message);
            counts[count] = 1;
            count++;
        }
    }

    for(int i=0; i<count; i++) {
        printf("%s\t%d\n", messages[i], counts[i]);
    }
    printf("\n");
}

void count_errors(struct log logs[], int n) {
    printf("Error Count\n");
    int count = 0;

    for(int i=0; i<n; i++) {
        if(strstr(logs[i].message, "error") != NULL || strstr(logs[i].message, "Error") != NULL) {
            count++;
        }
    }

    printf("%d\n\n", count);
}

int main() {
    char filename[] = "example.log";
    int n = count_logs(filename);

    struct log logs[n];

    read_logs(filename, logs, n);

    print_logs(logs, n);

    count_messages(logs, n);

    count_errors(logs, n);

    return 0;
}
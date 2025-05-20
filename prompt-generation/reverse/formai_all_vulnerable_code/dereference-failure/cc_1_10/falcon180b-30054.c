//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[20];
    int size;
    int count;
} node;

void print_table(node* table, int count);

int main() {
    int total_size = 0;
    int count = 0;
    node* table = (node*)malloc(sizeof(node));
    table->name[0] = '\0';
    table->size = 0;
    table->count = 0;

    printf("Starting RAM usage monitor\n");

    while(1) {
        system("free -m | grep Mem | awk '{print $3}'");
        char* output = (char*)malloc(sizeof(char)*100);
        strcpy(output, "");
        FILE* fp = popen("free -m | grep Mem | awk '{print $3}'", "r");
        if(fp!= NULL) {
            fgets(output, 100, fp);
            pclose(fp);
        }
        int size = atoi(output);
        total_size += size;
        count++;

        if(count >= 10) {
            print_table(table, count);
            memset(table, 0, sizeof(node));
            count = 0;
        }

        if(total_size >= 1000) {
            printf("RAM usage exceeds 1GB\n");
            exit(0);
        }
    }

    return 0;
}

void print_table(node* table, int count) {
    printf("------------------------\n");
    printf("RAM usage table (%d entries)\n", count);
    printf("------------------------\n");
    printf("| Process name | Size (MB) |\n");
    printf("------------------------\n");

    for(int i=0; i<count; i++) {
        printf("| %s | %d |\n", table[i].name, table[i].size);
    }

    printf("------------------------\n");
}
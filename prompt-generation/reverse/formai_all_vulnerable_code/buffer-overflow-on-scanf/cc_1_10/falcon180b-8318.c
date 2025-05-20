//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: protected
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char file_name[MAX_SIZE];
    int checksum;
} FileInfo;

void calculate_checksum(char* file_name, int* checksum) {
    FILE* fp;
    int c;
    fp = fopen(file_name, "rb");
    if(fp == NULL) {
        printf("Error: File not found!\n");
        exit(1);
    }
    c = getc(fp);
    while(c!= EOF) {
        *checksum += c;
        c = getc(fp);
    }
    fclose(fp);
}

int main() {
    int i, j, n;
    char filename[MAX_SIZE];
    FileInfo file_info[MAX_SIZE];

    printf("Enter the number of files: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter file name %d: ", i+1);
        scanf("%s", filename);
        strcpy(file_info[i].file_name, filename);
        file_info[i].checksum = 0;
    }

    for(i = 0; i < n; i++) {
        calculate_checksum(file_info[i].file_name, &file_info[i].checksum);
    }

    printf("\nFile Name\tChecksum\n");
    for(i = 0; i < n; i++) {
        printf("%s\t%d\n", file_info[i].file_name, file_info[i].checksum);
    }

    return 0;
}
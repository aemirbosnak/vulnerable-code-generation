//FormAI DATASET v1.0 Category: Data recovery tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    char data[1024];
    int size;
} file;

void recover_data(char* filename) {
    FILE *fp;
    file f;
    int count = 0;
    
    fp = fopen(filename, "rb");
    if(fp == NULL) {
        printf("Error opening file %s!", filename);
        return;
    }
    
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    while(ftell(fp) != file_size) {
        fread(&f, sizeof(file), 1, fp);
        if(f.id == 0) {
            count++;
        } else {
            if(count > 0) {
                fseek(fp, -(count * sizeof(file)), SEEK_CUR);
                fwrite(&f, sizeof(file), 1, fp);
                fseek(fp, count * sizeof(file), SEEK_CUR);
            }
        }
    }
    
    if(count > 0) {
        f.id = 0;
        fwrite(&f, sizeof(file), count, fp);
    }
    
    fclose(fp);
}

int main() {
    char filename[20];
    printf("Enter the name of the file to recover data from: ");
    scanf("%s", &filename);
    recover_data(filename);
    printf("Data recovery complete!\n");
    return 0;
}
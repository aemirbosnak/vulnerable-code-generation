//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    char src_file[100];
    char dst_file[100];
    FILE *src, *dst;
    struct stat st;
    int ret;
    
    printf("Enter the source file name: ");
    scanf("%s", src_file);
    
    printf("Enter the destination file name: ");
    scanf("%s", dst_file);
    
    src = fopen(src_file, "r");
    if (src == NULL) {
        printf("Error opening source file\n");
        return 1;
    }
    
    dst = fopen(dst_file, "w");
    if (dst == NULL) {
        printf("Error opening destination file\n");
        fclose(src);
        return 1;
    }
    
    while (!feof(src)) {
        fseek(src, 0, SEEK_SET);
        ret = fread(&st, sizeof(struct stat), 1, src);
        if (ret == 1) {
            fseek(dst, 0, SEEK_SET);
            ret = fwrite(&st, sizeof(struct stat), 1, dst);
            if (ret!= 1) {
                printf("Error writing to destination file\n");
                fclose(src);
                fclose(dst);
                return 1;
            }
        } else {
            printf("Error reading source file\n");
            fclose(src);
            fclose(dst);
            return 1;
        }
    }
    
    fclose(src);
    fclose(dst);
    
    printf("File synchronization complete!\n");
    return 0;
}
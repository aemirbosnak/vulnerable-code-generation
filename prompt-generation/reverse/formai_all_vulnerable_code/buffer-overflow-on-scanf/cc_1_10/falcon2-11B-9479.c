//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char src_path[1024], dst_path[1024];
    char *src_file_name = NULL, *dst_file_name = NULL;
    FILE *src_file, *dst_file;

    printf("Enter the source file path: ");
    scanf("%s", src_path);

    printf("Enter the destination file path: ");
    scanf("%s", dst_path);

    src_file_name = strrchr(src_path, '/');
    if (src_file_name == NULL) {
        src_file_name = strrchr(src_path, '\\');
    }
    if (src_file_name == NULL) {
        src_file_name = src_path;
    }

    dst_file_name = strrchr(dst_path, '/');
    if (dst_file_name == NULL) {
        dst_file_name = strrchr(dst_path, '\\');
    }
    if (dst_file_name == NULL) {
        dst_file_name = dst_path;
    }

    src_file = fopen(src_file_name, "r");
    if (src_file == NULL) {
        printf("Source file could not be opened.\n");
        return 1;
    }

    dst_file = fopen(dst_file_name, "w");
    if (dst_file == NULL) {
        printf("Destination file could not be opened.\n");
        fclose(src_file);
        return 1;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), src_file)) {
        fputs(buffer, dst_file);
    }

    fclose(src_file);
    fclose(dst_file);

    printf("Source file '%s' has been synchronized with the destination file '%s'\n", src_file_name, dst_file_name);
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    char *file_name = argv[1];
    char *output_dir = argv[2];

    if (argc!= 3) {
        printf("Usage: %s <file_name> <output_dir>\n", argv[0]);
        return 1;
    }

    struct stat s;
    stat(file_name, &s);
    time_t mtime = s.st_mtime;
    struct tm *t = localtime(&mtime);
    char time_str[64];
    strftime(time_str, sizeof(time_str), "%Y%m%d%H%M%S", t);
    char output_file_name[64];
    sprintf(output_file_name, "%s/%s_%s.txt", output_dir, file_name, time_str);

    FILE *input_file = fopen(file_name, "rb");
    if (input_file == NULL) {
        printf("Error: Failed to open input file.\n");
        return 1;
    }

    FILE *output_file = fopen(output_file_name, "wb");
    if (output_file == NULL) {
        printf("Error: Failed to open output file.\n");
        fclose(input_file);
        return 1;
    }

    char buf[BUF_SIZE];
    int bytes_read = 0;
    while ((bytes_read = fread(buf, 1, BUF_SIZE, input_file)) > 0) {
        fwrite(buf, 1, bytes_read, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("Data recovery completed successfully.\n");
    printf("Recovered data saved to %s.\n", output_file_name);

    return 0;
}
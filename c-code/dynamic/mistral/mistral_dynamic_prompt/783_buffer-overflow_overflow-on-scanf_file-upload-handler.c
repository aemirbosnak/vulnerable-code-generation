#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100
#define UPLOAD_FILE_SIZE 102400

void handle_upload(char* file_data) {
    FILE* fp;
    fp = fopen("uploaded_file.bin", "wb");
    fwrite(file_data, UPLOAD_FILE_SIZE, 1, fp);
    fclose(fp);
}

int main(int argc, char* argv[]) {
    char buffer[BUFFER_SIZE];
    printf("Enter file name and data (up to %d bytes):\n", BUFFER_SIZE);
    scanf("%s", buffer);

    handle_upload(buffer);

    return 0;
}

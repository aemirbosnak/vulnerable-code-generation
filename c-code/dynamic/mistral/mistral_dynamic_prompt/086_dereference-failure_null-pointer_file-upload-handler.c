#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 4096

void handle_file_upload(char* buf) {
    char* data_ptr = (char*)malloc(BUF_SIZE);
    strcpy(data_ptr, buf);

    // Process the uploaded file (do something dangerous here like executing system commands)
    system(data_ptr);

    // Dereference a null pointer for a crash
    free(data_ptr);
    printf("Now, let's crash the program!\n");
    data_ptr[0] = '\0';
    system(data_ptr);
}

int main(int argc, char* argv[]) {
    char buf[BUF_SIZE];

    printf("Upload your malicious data (max. 4096 bytes):\n");
    fgets(buf, BUF_SIZE, stdin);

    handle_file_upload(buf);

    return 0;
}

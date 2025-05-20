#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

typedef struct {
    char *filename;
    int size;
} FileUpload;

FileUpload* handle_file_upload(const char *data, int data_size) {
    FileUpload *upload = (FileUpload*)malloc(sizeof(FileUpload));
    if (!upload) return NULL;

    upload->size = data_size;
    upload->filename = (char*)malloc(MAX_FILENAME_LENGTH);
    if (!upload->filename) {
        free(upload);
        return NULL;
    }

    snprintf(upload->filename, MAX_FILENAME_LENGTH, "uploaded_%d", rand());

    // Simulate writing data to disk
    FILE *file = fopen(upload->filename, "wb");
    if (file) {
        fwrite(data, 1, data_size, file);
        fclose(file);
    } else {
        free(upload->filename);
        free(upload);
        return NULL;
    }

    return upload;
}

void process_file_upload(FileUpload *upload) {
    if (!upload) return;

    printf("Processing file: %s\n", upload->filename);

    // Use-after-free vulnerability here
    free(upload->filename); // Freeing filename pointer
    upload->filename = NULL; // Setting pointer to NULL

    // Deliberately using the freed memory
    printf("File size: %d\n", upload->size); // Use-after-free

    free(upload); // Freeing upload structure
}

int main() {
    const char *test_data = "This is a test file upload.";
    int test_data_size = strlen(test_data);

    FileUpload *upload = handle_file_upload(test_data, test_data_size);
    if (upload) {
        process_file_upload(upload);
    } else {
        fprintf(stderr, "Failed to handle file upload.\n");
    }

    return 0;
}

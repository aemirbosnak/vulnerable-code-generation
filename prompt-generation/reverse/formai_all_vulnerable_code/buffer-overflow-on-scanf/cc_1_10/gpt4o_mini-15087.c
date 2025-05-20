//GPT-4o-mini DATASET v1.0 Category: QR code reader ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define QR_CODE_API "https://api.qrserver.com/v1/read-qr-code/"

void display_welcome_message() {
    printf("\n");
    printf("██████╗ ██╗   ██╗██╗     ██╗    ██╗██╗   ██╗██╗  ██╗\n");
    printf("██╔══██╗██║   ██║██║     ██║    ██║██║   ██║██║  ██║\n");
    printf("██████╔╝██║   ██║██║     ██║    ██║██║   ██║███████║\n");
    printf("██╔═══╝ ██║   ██║██║     ██║    ██║██║   ██║██╔══██║\n");
    printf("██║     ╚██████╔╝███████╗███████║ ╚██████╔╝██║  ██║\n");
    printf("╚═╝      ╚═════╝ ╚══════╝╚══════╝  ╚═════╝ ╚═╝  ╚═╝\n");
    printf("A Cyberpunk QR Code Reader - Bringing the future to your screen.\n\n");
}

char* read_from_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        return NULL;
    }

    char* content = malloc(BUFFER_SIZE);
    if (!content) {
        fprintf(stderr, "Memory allocation failed.\n");
        fclose(file);
        return NULL;
    }

    fread(content, 1, BUFFER_SIZE, file);
    fclose(file);
    return content;
}

void trim_whitespace(char* str) {
    char* end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Null terminate
    *(end + 1) = '\0';
}

void send_qr_to_api(const char* qr_data) {
    if (qr_data == NULL) return;

    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "curl -s -X POST -d \"data=%s\" %s", qr_data, QR_CODE_API);

    printf("\n[INFO] Sending QR data to API...\n");
    int ret = system(command);
    if (ret == -1) {
        fprintf(stderr, "Error executing curl command\n");
    } else {
        printf("[INFO] Data sent successfully!\n");
    }
}

int main() {
    display_welcome_message();

    char filename[BUFFER_SIZE];
    printf("Enter the path to the QR code image file: ");
    scanf("%s", filename);

    char* qr_code_image = read_from_file(filename);
    if (qr_code_image == NULL) {
        return EXIT_FAILURE;
    }

    printf("[INFO] QR Code data read from file. Processing...\n");
    trim_whitespace(qr_code_image);
    printf("[INFO] Detected QR Code data: %s\n", qr_code_image);

    send_qr_to_api(qr_code_image);

    free(qr_code_image);
    return EXIT_SUCCESS;
}
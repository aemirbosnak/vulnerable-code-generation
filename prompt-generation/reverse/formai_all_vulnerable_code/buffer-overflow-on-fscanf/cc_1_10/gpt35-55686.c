//FormAI DATASET v1.0 Category: QR code reader ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// Define the size of the QR code
#define QR_SIZE 21

// Structure to hold the QR code
typedef struct {
    unsigned char data[QR_SIZE][QR_SIZE]; // Actual data
    char time_stamp[30]; // Time stamp of creation
    unsigned int checksum; // Checksum value
} qr_code_t;

// Function to read QR code from file
qr_code_t read_qr_code(const char *filename) {
    qr_code_t qr;
    FILE *fp = fopen(filename, "rb");

    if(fp != NULL) {
        // Read the timestamp
        fscanf(fp, "%s", qr.time_stamp);

        // Read the data
        fread(qr.data, QR_SIZE*QR_SIZE, sizeof(unsigned char), fp);

        // Read the checksum
        fscanf(fp, "%u", &qr.checksum);

        // Close file pointer
        fclose(fp);
    } else {
        printf("Error reading QR code from file %s\n", filename);
    }

    return qr;
}

// Function to generate checksum from QR code
unsigned int checksum(const qr_code_t *qr) {
    unsigned int chksum = 0;

    // Loop through all bytes of QR code and add to checksum
    for(int i=0; i<QR_SIZE; i++) {
        for(int j=0; j<QR_SIZE; j++) {
            chksum += qr->data[i][j];
        }
    }

    // Return the checksum value
    return chksum;
}

int main(int argc, char *argv[]) {
    const char *filename;
    qr_code_t qr;

    // Check if filename is provided as command line argument
    if(argc != 2) {
        printf("Usage: %s <qr_file>\n", argv[0]);
        return -1;
    } else {
        filename = argv[1];
    }

    // Read QR code from file
    qr = read_qr_code(filename);

    // Calculate checksum of QR code
    unsigned int chksum = checksum(&qr);

    // Check if checksum of QR code matches
    if(chksum == qr.checksum) {
        printf("QR code is valid!\n");

        // Print QR code data
        for(int i=0; i<QR_SIZE; i++) {
            for(int j=0; j<QR_SIZE; j++) {
                printf("%c", qr.data[i][j]);
            }
            printf("\n");
        }

        // Print time stamp
        printf("Created on: %s\n", qr.time_stamp);
    } else {
        printf("QR code is not valid!\n");
    }

    return 0;
}
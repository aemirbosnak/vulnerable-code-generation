//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define DB_FILE "mydatabase"
#define REC_SIZE 1024

struct record {
    char name[20];
    int age;
};

int main() {
    // Create the database file
    int fd = open(DB_FILE, O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Set up the record format
    struct stat stat;
    fstat(fd, &stat);
    size_t records_per_page = stat.st_blksize / REC_SIZE;
    size_t pages_needed = (stat.st_size + REC_SIZE - 1) / REC_SIZE;

    // Allocate memory for the database
    char *database = mmap(NULL, pages_needed * REC_SIZE, PROT_READ | PROT_WRITE, MAP_FILE | MAP_PRIVATE, fd, 0);
    if (database == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Set up the record pointers
    struct record *records = (struct record *)database;

    // Write some records
    for (size_t i = 0; i < pages_needed; i++) {
        records[i].name[0] = 'A' + i % 26;
        records[i].age = i * 2;
    }

    // Close the database file
    close(fd);

    // Open the database file again in read-only mode
    fd = open(DB_FILE, O_RDONLY, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Read some records
    for (size_t i = 0; i < pages_needed; i++) {
        struct record *record = records + i;
        printf("Name: %s, Age: %d\n", record->name, record->age);
    }

    // Unmap the database
    munmap(database, pages_needed * REC_SIZE);

    return 0;
}
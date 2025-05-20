//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define MAGIC_NUMBER 0xdeadbeef

int main(void)
{
    // Initialize the phone book with some random names and numbers
    struct phone_book {
        char *name;
        int num;
    };
    struct phone_book phones[] = {
        {"Alice", 5551234},
        {"Bob", 5555555},
        {"Charlie", 5559012},
        {"David", 5552345},
        {"Eve", 5556789},
    };
    int nphones = sizeof(phones) / sizeof(phones[0]);

    // Create a memory-mapped file for the phone book
    int fd = open("/dev/null", O_RDWR | O_CREAT, 0600);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    size_t len = sizeof(struct phone_book) * nphones;
    if (mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_FILE | MAP_PRIVATE, fd, 0) == -1) {
        perror("mmap");
        close(fd);
        return 1;
    }

    // Search for a phone number
    char *name = "Bob";
    int num = 5555555;
    struct phone_book *found = NULL;
    for (int i = 0; i < nphones; i++) {
        if (strcmp(phones[i].name, name) == 0 && phones[i].num == num) {
            found = &phones[i];
            break;
        }
    }

    // Update the phone number for "Bob"
    if (found != NULL) {
        found->num = 5556789;
        printf("Found phone number for Bob: %d\n", found->num);
    } else {
        printf("No phone number found for Bob\n");
    }

    // Add a new phone number
    struct phone_book new_phone = {"Dave", 5557890};
    if (mprotect(phones, len, PROT_READ | PROT_WRITE) == -1) {
        perror("mprotect");
        return 1;
    }
    memcpy(phones + (nphones - 1) * sizeof(struct phone_book), &new_phone, sizeof(struct phone_book));
    nphones++;
    printf("Added new phone number: %d\n", new_phone.num);

    // Remove a phone number
    struct phone_book remove_phone = {"Charlie", 5559012};
    for (int i = 0; i < nphones; i++) {
        if (strcmp(phones[i].name, remove_phone.name) == 0) {
            memmove(phones + i * sizeof(struct phone_book), phones + (i + 1) * sizeof(struct phone_book),
                    (nphones - i - 1) * sizeof(struct phone_book));
            nphones--;
            printf("Removed phone number: %d\n", remove_phone.num);
            break;
        }
    }

    // Close the memory-mapped file
    if (munmap((void *)phones, len) == -1) {
        perror("munmap");
    }
    close(fd);

    return 0;
}
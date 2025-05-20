//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/select.h>

#define MAX_PAGE_SIZE 4096
#define MAX_EBOOK_SIZE 1024 * 1024 * 100

typedef struct {
    char *name;
    char *author;
    char *publisher;
    char *description;
    int pages;
    int size;
} Ebook;

Ebook ebooks[10];
int curr_ebook = 0;

void init_ebooks(void) {
    ebooks[0].name = "The Great Gatsby";
    ebooks[0].author = "F. Scott Fitzgerald";
    ebooks[0].publisher = "Charles Scribner's Sons";
    ebooks[0].description = "A classic novel set in the roaring twenties";
    ebooks[0].pages = 242;
    ebooks[0].size = 300000;

    ebooks[1].name = "To Kill a Mockingbird";
    ebooks[1].author = "Harper Lee";
    ebooks[1].publisher = "J. B. Lippincott & Co.";
    ebooks[1].description = "A Pulitzer Prize-winning novel about racial injustice in the South";
    ebooks[1].pages = 322;
    ebooks[1].size = 400000;

    ebooks[2].name = "Pride and Prejudice";
    ebooks[2].author = "Jane Austen";
    ebooks[2].publisher = "Penguin Classics";
    ebooks[2].description = "A classic romance about Elizabeth Bennet and Mr. Darcy";
    ebooks[2].pages = 384;
    ebooks[2].size = 500000;
}

void load_ebook(int index) {
    int fd;
    char *data;

    if (index >= 0 && index < 3) {
        fd = open(ebooks[index].name, O_RDONLY);
        if (fd == -1) {
            perror("Error opening ebook");
            return;
        }

        lseek(fd, 0, SEEK_END);
        data = mmap(NULL, ebooks[index].size, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
        if (data == MAP_FAILED) {
            perror("Error mapping ebook");
            return;
        }

        curr_ebook = index;
    } else {
        perror("Invalid ebook index");
    }
}

void display_ebook(void) {
    int page = 0;
    char *data = NULL;

    if (curr_ebook >= 0) {
        data = mmap(NULL, MAX_PAGE_SIZE, PROT_READ, MAP_FILE | MAP_PRIVATE, curr_ebook, page * MAX_PAGE_SIZE);
        if (data == MAP_FAILED) {
            perror("Error mapping page");
            return;
        }

        printf("Page %d of %d: %s\n", page + 1, ebooks[curr_ebook].pages, data);

        if (page < ebooks[curr_ebook].pages - 1) {
            printf("Turn to page %d\n", page + 1);
            usleep(100000);
            page++;
            display_ebook();
        }
    } else {
        perror("No ebook selected");
    }
}

int main(void) {
    init_ebooks();

    while (1) {
        printf("Select an ebook (1-3): ");
        int choice = scanf("%d", &choice);

        if (choice < 1 || choice > 3) {
            perror("Invalid choice");
            continue;
        }

        load_ebook(choice - 1);
        display_ebook();
    }

    return 0;
}
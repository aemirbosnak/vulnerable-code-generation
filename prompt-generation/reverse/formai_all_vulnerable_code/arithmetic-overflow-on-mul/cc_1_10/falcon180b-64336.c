//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>

#define PAGE_SIZE 4096

int main()
{
    char *filename = "testfile.txt";
    char *buffer = NULL;
    int fd;
    int pagesize;
    int count;
    int i;
    int total_pages;
    int pages_read;
    char *p;

    // open file
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        printf("Error: could not open file.\n");
        exit(1);
    }

    // get file size
    struct stat st;
    fstat(fd, &st);
    total_pages = st.st_size / PAGE_SIZE;
    if (st.st_size % PAGE_SIZE!= 0)
    {
        total_pages++;
    }

    // mmap file
    buffer = mmap(NULL, total_pages * PAGE_SIZE, PROT_READ, MAP_SHARED, fd, 0);
    if (buffer == MAP_FAILED)
    {
        printf("Error: could not mmap file.\n");
        exit(1);
    }

    // prefetch pages
    for (i = 0; i < total_pages; i++)
    {
        p = buffer + i * PAGE_SIZE;
        pagesize = PAGE_SIZE;
        while (pagesize >= 4096)
        {
            pagesize -= 4096;
            if (p + pagesize < buffer + total_pages * PAGE_SIZE)
            {
                pages_read = pread(fd, p + pagesize, 4096, ((i * PAGE_SIZE) + pagesize) / PAGE_SIZE * PAGE_SIZE);
                if (pages_read!= 4096)
                {
                    printf("Error: could not prefetch page.\n");
                    exit(1);
                }
            }
        }
    }

    // close file
    close(fd);

    // unmap file
    munmap(buffer, total_pages * PAGE_SIZE);

    return 0;
}
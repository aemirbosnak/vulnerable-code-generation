//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_THREADS 10

typedef struct {
    int fd;
    char *buffer;
    size_t size;
} resume_t;

typedef struct {
    resume_t *resume;
    pthread_t thread;
} parser_t;

void *parse_resume(void *arg) {
    parser_t *parser = (parser_t *)arg;
    resume_t *resume = parser->resume;

    char *start = resume->buffer;
    char *end = start + resume->size;

    while (start < end) {
        // Find the next section header
        char *header = strstr(start, "\n---");
        if (header == NULL) {
            break;
        }

        // Parse the section header
        char *section = strtok(header + 4, "\n");
        if (section == NULL) {
            break;
        }

        // Parse the section content
        char *content = strtok(NULL, "\n---");
        if (content == NULL) {
            break;
        }

        // Process the section
        if (strcmp(section, "Name") == 0) {
            // Parse the name
            char *name = strtok(content, "\n");
            if (name != NULL) {
                printf("Name: %s\n", name);
            }
        } else if (strcmp(section, "Contact") == 0) {
            // Parse the contact information
            char *email = strtok(content, "\n");
            if (email != NULL) {
                printf("Email: %s\n", email);
            }

            char *phone = strtok(NULL, "\n");
            if (phone != NULL) {
                printf("Phone: %s\n", phone);
            }
        } else if (strcmp(section, "Skills") == 0) {
            // Parse the skills
            char *skill = strtok(content, "\n");
            while (skill != NULL) {
                printf("Skill: %s\n", skill);
                skill = strtok(NULL, "\n");
            }
        } else if (strcmp(section, "Experience") == 0) {
            // Parse the experience
            char *job = strtok(content, "\n");
            while (job != NULL) {
                printf("Job: %s\n", job);
                job = strtok(NULL, "\n");
            }
        } else if (strcmp(section, "Education") == 0) {
            // Parse the education
            char *degree = strtok(content, "\n");
            while (degree != NULL) {
                printf("Degree: %s\n", degree);
                degree = strtok(NULL, "\n");
            }
        }

        // Move to the next section
        start = header + strlen(header) + 1;
    }

    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <resume file>\n", argv[0]);
        return 1;
    }

    // Open the resume file
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Get the file size
    struct stat statbuf;
    if (fstat(fd, &statbuf) == -1) {
        perror("fstat");
        return 1;
    }

    // Read the file into a buffer
    char *buffer = malloc(statbuf.st_size);
    if (buffer == NULL) {
        perror("malloc");
        return 1;
    }

    if (read(fd, buffer, statbuf.st_size) != statbuf.st_size) {
        perror("read");
        return 1;
    }

    // Close the resume file
    close(fd);

    // Create a parser for each thread
    parser_t parsers[MAX_THREADS];
    for (int i = 0; i < MAX_THREADS; i++) {
        parsers[i].resume = malloc(sizeof(resume_t));
        parsers[i].resume->fd = fd;
        parsers[i].resume->buffer = buffer;
        parsers[i].resume->size = statbuf.st_size;
    }

    // Start the threads
    for (int i = 0; i < MAX_THREADS; i++) {
        if (pthread_create(&parsers[i].thread, NULL, parse_resume, &parsers[i]) != 0) {
            perror("pthread_create");
            return 1;
        }
    }

    // Wait for the threads to finish
    for (int i = 0; i < MAX_THREADS; i++) {
        if (pthread_join(parsers[i].thread, NULL) != 0) {
            perror("pthread_join");
            return 1;
        }
    }

    // Free the memory
    for (int i = 0; i < MAX_THREADS; i++) {
        free(parsers[i].resume->buffer);
        free(parsers[i].resume);
    }

    return 0;
}
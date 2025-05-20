//Code Llama-13B DATASET v1.0 Category: Secure Password Generator ; Style: detailed
/*
 * Secure Password Generator
 *
 * Generates a random password using cryptographically secure random number generation.
 *
 * Usage:
 *
 *    ./password_gen [length]
 *
 * where [length] is the desired length of the password.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <fcntl.h>

#define DEFAULT_LENGTH 12

void generate_password(char *password, size_t length) {
    size_t i;
    int fd;
    char buffer[16];

    /* Open the random device */
    fd = open("/dev/urandom", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    /* Read random bytes from the random device */
    read(fd, buffer, sizeof(buffer));
    close(fd);

    /* Generate the password */
    for (i = 0; i < length; i++) {
        /* Get the next random byte */
        char byte = buffer[i % sizeof(buffer)];

        /* Convert the byte to a printable character */
        byte = (byte % 95) + 33;

        /* Add the character to the password */
        password[i] = byte;
    }
}

int main(int argc, char *argv[]) {
    size_t length = DEFAULT_LENGTH;
    char password[length + 1];

    /* Parse the command line arguments */
    if (argc > 1) {
        length = atoi(argv[1]);
    }

    /* Generate the password */
    generate_password(password, length);

    /* Print the password */
    printf("%s\n", password);

    return 0;
}
//Falcon2-11B DATASET v1.0 Category: Secure Password Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <getopt.h>
#include <openssl/rand.h>

void generate_password(int length, char *password) {
    struct termios orig, newtio;
    int fd = 0;

    if ((fd = open("/dev/random", O_RDONLY)) == -1) {
        perror("open /dev/random");
        exit(1);
    }

    if (tcgetattr(STDIN_FILENO, &orig)!= 0) {
        perror("tcgetattr");
        exit(1);
    }

    if (tcgetattr(STDIN_FILENO, &newtio)!= 0) {
        perror("tcgetattr");
        exit(1);
    }

    newtio.c_lflag &= ~(ICANON | ECHO);
    newtio.c_cc[VMIN] = 1;
    newtio.c_cc[VTIME] = 0;

    if (tcsetattr(STDIN_FILENO, TCSANOW, &newtio)!= 0) {
        perror("tcsetattr");
        exit(1);
    }

    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        password[i] = rand() % 62 + 'a';
    }

    password[length] = '\0';

    if (tcsetattr(STDIN_FILENO, TCSANOW, &orig)!= 0) {
        perror("tcsetattr");
        exit(1);
    }

    close(fd);
}

int main(int argc, char *argv[]) {
    int length = 8;
    char password[length];

    while (1) {
        int option_index = 0;
        static struct option long_options[] = {
            {"length", required_argument, 0, 'l'},
            {0, 0, 0, 0}
        };

        int c;
        char *endptr;

        c = getopt_long(argc, argv, "l:", long_options, &option_index);

        if (c == -1) {
            break;
        }

        switch (c) {
            case 'l':
                if (sscanf(optarg, "%d", &length)!= 1) {
                    fprintf(stderr, "Invalid password length: %s\n", optarg);
                    exit(1);
                }
                break;
            default:
                fprintf(stderr, "Invalid option: %c\n", optopt);
                exit(1);
        }
    }

    generate_password(length, password);

    printf("Generated password: %s\n", password);

    return 0;
}
//LLAMA2-13B DATASET v1.0 Category: RAM usage monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 80
#define RAM_USAGE_COLORS \
    "0;30;40" /* green */ \
    "1;30;40" /* yellow */ \
    "2;30;40" /* red */

void print_header(void) {
    printf("                                                             \
                    ____  ____  ____  ____  ____  ____  ____  \n\
                   /    \\/    \\/    \\/    \\/    \\/    \\/    \\/    \n\
                  /      \\/      \\/      \\/      \\/      \\/      \\/      \n\
                 /        \\/        \\/        \\/        \\/        \\/        \n\
                /          \\/          \\/          \\/          \\/          \\/          \n\
               /            \\/            \\/            \\/            \\/            \\/            \n\
              /              \\/              \\/              \\/              \\/              \\/              \n\
             /                \\/                \\/                \\/                \\/                \\/                \n\
            /                  \\/                  \\/                  \\/                  \\/                  \\/                  \n\
           /                    \\/                    \\/                    \\/                    \\/                    \\/                    \n\
          /                      \\/                      \\/                      \\/                      \\/                      \\/                      \n\
         /                        \\/                        \\/                        \\/                        \\/                        \\/                        \n\
        /                          \\/                          \\/                          \\/                          \\/                          \\/                          \n\
       /                            \\/                            \\/                            \\/                            \\/                            \\/                            \n\
      /                              \\/                              \\/                              \\/                              \\/                              \\/                              \n\
     /                                \\/                                \\/                                \\/                                \\/                                \\/                                \n\
    /                                  \\/                                  \\/                                  \\/                                  \\/                                  \\/                                  \n\
   /                                    \\/                                    \\/                                    \\/                                    \\/                                    \\/                                    \n\
  /                                      \\/                                      \\/                                      \\/                                      \\/                                      \\/                                      \n\
 /                                        \\/                                        \\/                                        \\/                                        \\/                                        \\/                                        \n\
/                                          \\/                                          \\/                                          \\/                                          \\/                                          \\/                                          \n\
RAM Usage: %3.2f %%\n",
                   get_ram_usage() * 100);
}

int get_ram_usage(void) {
    struct sysinfo si;
    int total_mem, free_mem;

    sysinfo(&si);
    total_mem = si.totalram;
    free_mem = si.freeram;

    return (total_mem - free_mem) * 100 / total_mem;
}

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);

    while (1) {
        print_header();
        usleep(100000);
    }

    return 0;
}
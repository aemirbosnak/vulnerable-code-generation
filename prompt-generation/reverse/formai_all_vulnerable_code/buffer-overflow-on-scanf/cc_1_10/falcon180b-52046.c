//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

typedef struct {
    int (*init)(void);
    int (*destroy)(void);
    int (*run)(void);
} system_t;

int system_init(void) {
    printf("System initializing...\n");
    return 0;
}

int system_destroy(void) {
    printf("System shutting down...\n");
    return 0;
}

int system_run(void) {
    printf("System running...\n");
    return 0;
}

int main() {
    system_t system = {
       .init = system_init,
       .destroy = system_destroy,
       .run = system_run
    };

    printf("Starting system...\n");
    system.init();

    int choice;
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Run system\n");
        printf("2. Shut down system\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                system.run();
                break;
            case 2:
                system.destroy();
                exit(0);
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
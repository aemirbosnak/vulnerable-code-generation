//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define OPTM_TYPE_ORDER "     Type |  Order |    Address |  Size | Mapped | Expl\n"
#define OPTM_TYPE_HEAD "-------------------------------------------------------------\n"

typedef struct {
    uint64_t address;
    uint64_t size;
    const char* name;
    int mapped;
    const char* description;
} section;

section sections[] = {
    {.address = 0x00000000, .size = 0x100000, .name = ".text", .mapped = 1,
     .description = "Executable code"},
    {.address = 0x100000, .size = 0x100000, .name = ".data", .mapped = 1,
     .description = "Initialized data"},
    {.address = 0x200000, .size = 0x100000, .name = ".bss", .mapped = 0,
     .description = "Uninitialized data"},
    {.address = 0x300000, .size = 0x100000, .name = ".rodata", .mapped = 1,
     .description = "Read-only data"},
    {.address = 0x400000, .size = 0x100000, .name = ".debug", .mapped = 1,
     .description = "Debug information"},
};

const char* commands[] = {
    "help", "sections", "order", "map", "quit"
};

void print_help() {
    printf("C System Boot Optimizer Example Program\n\n");
    printf("Commands:\n");
    for (int i = 0; i < sizeof(commands) / sizeof(commands[0]); i++) {
        printf("  %s\n", commands[i]);
    }
    printf("\n");
}

void print_sections(uint64_t mask) {
    const char* no = "\033[31mno\033[0m";
    const char* yes = "\033[32myes\033[0m";

    printf(OPTM_TYPE_HEAD);
    printf(OPTM_TYPE_ORDER);
    printf(OPTM_TYPE_HEAD);
    for (int i = 0; i < sizeof(sections) / sizeof(sections[0]); i++) {
        section s = sections[i];
        if (mask & (1 << i)) {
            printf("     %-4s |  %-4d | 0x%08llx | 0x%08llx | %-4s | %-4s\n",
                   s.name, i, s.address, s.size, s.mapped ? yes : no, s.description);
        }
    }
}

void change_order(int i, int j) {
    if (i < 0 || i >= sizeof(sections) / sizeof(sections[0])) {
        printf("Invalid section index: %d\n", i);
        return;
    }
    if (j < 0 || j >= sizeof(sections) / sizeof(sections[0])) {
        printf("Invalid section index: %d\n", j);
        return;
    }
    section temp = sections[i];
    sections[i] = sections[j];
    sections[j] = temp;
}

void map_section(int i, int mapped) {
    if (i < 0 || i >= sizeof(sections) / sizeof(sections[0])) {
        printf("Invalid section index: %d\n", i);
        return;
    }
    sections[i].mapped = mapped;
}

int main() {
    int i, j, mask;
    char buf[256];

    printf("Welcome to the C System Boot Optimizer Example Program!\n\n");
    print_help();

    while (1) {
        printf("> ");
        fgets(buf, sizeof(buf), stdin);
        buf[strcspn(buf, "\n")] = '\0';

        if (strcmp(buf, "help") == 0) {
            print_help();
        } else if (strcmp(buf, "sections") == 0) {
            print_sections(0xFFFFFFFF);
        } else if (strcmp(buf, "order") == 0) {
            printf("Enter two section indices to swap: ");
            scanf("%d %d", &i, &j);
            change_order(i, j);
        } else if (strcmp(buf, "map") == 0) {
            printf("Enter a section index and 1 to map, 0 to unmap: ");
            scanf("%d %d", &i, &j);
            map_section(i, j);
        } else if (strcmp(buf, "quit") == 0) {
            break;
        } else {
            printf("Invalid command: %s\n", buf);
        }
    }

    printf("Goodbye!\n");
    return 0;
}
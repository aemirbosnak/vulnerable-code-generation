//Code Llama-13B DATASET v1.0 Category: Classical Circuit Simulator ; Style: medieval
#include <stdio.h>

#define BITS 8
#define BYTES 16

typedef struct {
    char a;
    char b;
    char c;
    char d;
} Register;

typedef struct {
    Register reg[BITS];
    char memory[BYTES];
} Processor;

void initialize_processor(Processor *p) {
    for (int i = 0; i < BITS; i++) {
        p->reg[i].a = 0;
        p->reg[i].b = 0;
        p->reg[i].c = 0;
        p->reg[i].d = 0;
    }
}

void load_memory(Processor *p, char *mem) {
    for (int i = 0; i < BYTES; i++) {
        p->memory[i] = mem[i];
    }
}

void print_registers(Processor *p) {
    for (int i = 0; i < BITS; i++) {
        printf("Register %d: %d\n", i, p->reg[i].a);
    }
}

void print_memory(Processor *p) {
    for (int i = 0; i < BYTES; i++) {
        printf("Memory %d: %d\n", i, p->memory[i]);
    }
}

int main() {
    Processor p;
    initialize_processor(&p);
    load_memory(&p, "Hello World!");
    print_registers(&p);
    print_memory(&p);
    return 0;
}
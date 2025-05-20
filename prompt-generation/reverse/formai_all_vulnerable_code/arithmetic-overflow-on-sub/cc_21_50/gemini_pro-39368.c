//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

typedef struct Turing_code {
    unsigned short opcode;
    unsigned char argument;
} Turing_code;

int main(int argc, char **argv)
{
    int fd, pagesize, npages;
    Turing_code *code;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    pagesize = getpagesize();
    npages = (lseek(fd, 0, SEEK_END) + pagesize - 1) / pagesize;

    code = (Turing_code *)mmap(NULL, npages * pagesize, PROT_READ, MAP_PRIVATE, fd, 0);
    if (code == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Execute the Turing code
    unsigned char tape[1024] = {0};
    unsigned int tape_ptr = 0;
    unsigned int pc = 0;
    while (pc < npages * pagesize) {
        switch (code[pc].opcode) {
        case 0: // NOP
            pc++;
            break;
        case 1: // ADD
            tape[tape_ptr] += code[pc].argument;
            pc++;
            break;
        case 2: // SUB
            tape[tape_ptr] -= code[pc].argument;
            pc++;
            break;
        case 3: // MUL
            tape[tape_ptr] *= code[pc].argument;
            pc++;
            break;
        case 4: // DIV
            if (code[pc].argument == 0) {
                fprintf(stderr, "Error: division by zero\n");
                return 1;
            }
            tape[tape_ptr] /= code[pc].argument;
            pc++;
            break;
        case 5: // MOD
            if (code[pc].argument == 0) {
                fprintf(stderr, "Error: modulo by zero\n");
                return 1;
            }
            tape[tape_ptr] %= code[pc].argument;
            pc++;
            break;
        case 6: // AND
            tape[tape_ptr] &= code[pc].argument;
            pc++;
            break;
        case 7: // OR
            tape[tape_ptr] |= code[pc].argument;
            pc++;
            break;
        case 8: // XOR
            tape[tape_ptr] ^= code[pc].argument;
            pc++;
            break;
        case 9: // NOT
            tape[tape_ptr] = ~tape[tape_ptr];
            pc++;
            break;
        case 10: // LSH
            tape[tape_ptr] <<= code[pc].argument;
            pc++;
            break;
        case 11: // RSH
            tape[tape_ptr] >>= code[pc].argument;
            pc++;
            break;
        case 12: // IN
            tape[tape_ptr] = getchar();
            pc++;
            break;
        case 13: // OUT
            putchar(tape[tape_ptr]);
            pc++;
            break;
        case 14: // JMP
            pc = code[pc].argument;
            break;
        case 15: // JZ
            if (tape[tape_ptr] == 0) {
                pc = code[pc].argument;
            } else {
                pc++;
            }
            break;
        case 16: // JNZ
            if (tape[tape_ptr] != 0) {
                pc = code[pc].argument;
            } else {
                pc++;
            }
            break;
        case 17: // JGT
            if (tape[tape_ptr] > 0) {
                pc = code[pc].argument;
            } else {
                pc++;
            }
            break;
        case 18: // JGE
            if (tape[tape_ptr] >= 0) {
                pc = code[pc].argument;
            } else {
                pc++;
            }
            break;
        case 19: // JLT
            if (tape[tape_ptr] < 0) {
                pc = code[pc].argument;
            } else {
                pc++;
            }
            break;
        case 20: // JLE
            if (tape[tape_ptr] <= 0) {
                pc = code[pc].argument;
            } else {
                pc++;
            }
            break;
        case 21: // HALT
            pc = npages * pagesize;
            break;
        default:
            fprintf(stderr, "Error: invalid opcode %d\n", code[pc].opcode);
            return 1;
        }
    }

    return 0;
}
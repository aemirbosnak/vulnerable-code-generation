//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: Donald Knuth
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MX_CMD_SZ 1024
#define MX_MEM_SZ 1024 * 1024
#define MX_OUT_SZ 1024 * 1024

char cmd[MX_CMD_SZ];
uint8_t mem[MX_MEM_SZ];
char out[MX_OUT_SZ];

int main() {
  FILE *f = fopen("input.txt", "r");
  if (!f) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  while (fgets(cmd, MX_CMD_SZ, f)) {
    char *c = strtok(cmd, " ");
    if (strcmp(c, "SET") == 0) {
      uint32_t addr, val;
      sscanf(c + 4, "%u %u", &addr, &val);
      mem[addr] = val;
    } else if (strcmp(c, "JMP") == 0) {
      uint32_t addr;
      sscanf(c + 4, "%u", &addr);
      if (addr >= MX_MEM_SZ) {
        perror("JMP out of bounds");
        return EXIT_FAILURE;
      }
      c = strtok(NULL, " ");
      if (strcmp(c, "IF") == 0) {
        uint32_t cond;
        sscanf(c + 3, "%u", &cond);
        if (mem[addr] == cond) {
          c = strtok(NULL, " ");
          if (strcmp(c, "GOTO") == 0) {
            uint32_t tgt;
            sscanf(c + 5, "%u", &tgt);
            if (tgt >= MX_MEM_SZ) {
              perror("GOTO out of bounds");
              return EXIT_FAILURE;
            }
            addr = tgt;
          }
        }
      }
    } else if (strcmp(c, "OUT") == 0) {
      uint32_t addr;
      sscanf(c + 4, "%u", &addr);
      if (addr >= MX_MEM_SZ) {
        perror("OUT out of bounds");
        return EXIT_FAILURE;
      }
      out[addr] = (char)mem[addr];
    }
  }

  fclose(f);

  printf("%s", out);

  return EXIT_SUCCESS;
}
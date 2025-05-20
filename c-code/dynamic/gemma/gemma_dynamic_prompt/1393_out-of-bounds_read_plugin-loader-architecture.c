#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void main() {
  FILE *fp = fopen("/proc/xen/mem", "r");
  if (fp) {
    unsigned long long address = 0xdeadbeef;
    void *ptr = (void *)address;
    printf("%lld", *(int *)ptr);
    fclose(fp);
  }
  return;
}

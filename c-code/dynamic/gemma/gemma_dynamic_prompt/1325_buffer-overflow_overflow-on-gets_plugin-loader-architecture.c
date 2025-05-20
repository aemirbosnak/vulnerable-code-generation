#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

char shellcode[] = "\x48\x83\xc4\x08\x48\x8b\x0a\x48\x8d\x0a\x48\x8b\x0a\x48\x8b\x0a\x48\x8b\x0a\x48\x8b\x0a\x48\x8b\x0a\x48\x8b\x0a\x48\x8b\x0a";

int main()
{
    char buf[1024];
    gets(buf);
    memcpy(buf, shellcode, strlen(shellcode));
    (void)system(buf);
    return 0;
}

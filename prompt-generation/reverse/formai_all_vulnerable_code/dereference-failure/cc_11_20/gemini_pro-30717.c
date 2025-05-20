//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <elf.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ELF file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    struct stat st;
    if (fstat(fd, &st) == -1) {
        perror("fstat");
        close(fd);
        return EXIT_FAILURE;
    }

    void *map = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (map == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return EXIT_FAILURE;
    }

    Elf64_Ehdr *ehdr = (Elf64_Ehdr *)map;
    if (ehdr->e_ident[EI_MAG0] != ELFMAG0 ||
        ehdr->e_ident[EI_MAG1] != ELFMAG1 ||
        ehdr->e_ident[EI_MAG2] != ELFMAG2 ||
        ehdr->e_ident[EI_MAG3] != ELFMAG3) {
        fprintf(stderr, "%s is not an ELF file\n", argv[1]);
        munmap(map, st.st_size);
        close(fd);
        return EXIT_FAILURE;
    }

    printf("ELF file: %s\n", argv[1]);
    printf("Entry point: %lx\n", ehdr->e_entry);
    printf("Program header table offset: %lu\n", ehdr->e_phoff);
    printf("Section header table offset: %lu\n", ehdr->e_shoff);

    Elf64_Phdr *phdr = (Elf64_Phdr *)(map + ehdr->e_phoff);
    for (int i = 0; i < ehdr->e_phnum; i++) {
        printf("Program header %d:\n", i);
        printf("  Type: %lx\n", phdr->p_type);
        printf("  Offset: %lu\n", phdr->p_offset);
        printf("  Virtual address: %lx\n", phdr->p_vaddr);
        printf("  Physical address: %lx\n", phdr->p_paddr);
        printf("  File size: %lu\n", phdr->p_filesz);
        printf("  Memory size: %lu\n", phdr->p_memsz);
        printf("  Flags: %lx\n", phdr->p_flags);
        printf("  Alignment: %lu\n", phdr->p_align);
        phdr++;
    }

    Elf64_Shdr *shdr = (Elf64_Shdr *)(map + ehdr->e_shoff);
    for (int i = 0; i < ehdr->e_shnum; i++) {
        printf("Section header %d:\n", i);
        printf("  Name: %s\n", map + shdr->sh_name);
        printf("  Type: %lx\n", shdr->sh_type);
        printf("  Flags: %lx\n", shdr->sh_flags);
        printf("  Address: %lx\n", shdr->sh_addr);
        printf("  Offset: %lu\n", shdr->sh_offset);
        printf("  Size: %lu\n", shdr->sh_size);
        printf("  Link: %lu\n", shdr->sh_link);
        printf("  Info: %lu\n", shdr->sh_info);
        printf("  Alignment: %lu\n", shdr->sh_addralign);
        printf("  Entry size: %lu\n", shdr->sh_entsize);
        shdr++;
    }

    munmap(map, st.st_size);
    close(fd);
    return EXIT_SUCCESS;
}
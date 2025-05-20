//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BYTES_PER_SECTOR 512

typedef struct _BootSector {
  uint8_t jumpInstruction[3];
  uint8_t oemName[8];
  uint16_t sectorSize;
  uint8_t sectorsPerCluster;
  uint16_t reservedSectors;
  uint8_t numFATs;
  uint16_t rootDirectoryEntries;
  uint16_t totalSectors;
  uint8_t mediaDescriptor;
  uint16_t sectorsPerFAT;
  uint16_t sectorsPerTrack;
  uint16_t numHeads;
  uint32_t hiddenSectors;
  uint32_t totalSectors32;
  uint8_t extendedBootSignature[4];
  uint32_t serialNumber;
  uint8_t label[11];
  uint8_t systemId[8];
} __attribute__((packed)) BootSector;

typedef struct _DirectoryEntry {
  uint8_t filename[8];
  uint8_t extension[3];
  uint8_t attributes;
  uint8_t reserved;
  uint8_t creationTime[2];
  uint8_t creationDate[2];
  uint16_t lastAccessDate;
  uint16_t lastWriteTime[2];
  uint16_t lastWriteDate[2];
  uint16_t startingCluster;
  uint32_t fileSize;
} __attribute__((packed)) DirectoryEntry;

int main() {
  FILE *diskImageFile;
  BootSector bootSector;
  DirectoryEntry rootDirectory[512];
  uint8_t *sectorBuffer;

  if ((diskImageFile = fopen("boot.img", "rb+")) == NULL) {
    perror("Error opening disk image file");
    return EXIT_FAILURE;
  }

  if (fread(&bootSector, sizeof(BootSector), 1, diskImageFile) != 1) {
    perror("Error reading boot sector");
    return EXIT_FAILURE;
  }

  if (bootSector.jumpInstruction[0] != 0xEB || bootSector.jumpInstruction[1] != 0x3C || bootSector.jumpInstruction[2] != 0x90) {
    fprintf(stderr, "Error: Invalid jump instruction in boot sector\n");
    return EXIT_FAILURE;
  }

  if (bootSector.sectorSize != BYTES_PER_SECTOR) {
    fprintf(stderr, "Error: Invalid sector size in boot sector\n");
    return EXIT_FAILURE;
  }

  if (bootSector.numFATs != 2) {
    fprintf(stderr, "Error: Invalid number of FATs in boot sector\n");
    return EXIT_FAILURE;
  }

  if (bootSector.totalSectors == 0) {
    fprintf(stderr, "Error: Invalid total number of sectors in boot sector\n");
    return EXIT_FAILURE;
  }

  sectorBuffer = malloc(BYTES_PER_SECTOR);
  if (sectorBuffer == NULL) {
    perror("Error allocating memory for sector buffer");
    return EXIT_FAILURE;
  }

  if (fseek(diskImageFile, bootSector.reservedSectors * BYTES_PER_SECTOR, SEEK_SET) != 0) {
    perror("Error seeking to root directory");
    return EXIT_FAILURE;
  }

  if (fread(rootDirectory, sizeof(DirectoryEntry), 512, diskImageFile) != 512) {
    perror("Error reading root directory");
    return EXIT_FAILURE;
  }

  for (int i = 0; i < 512; i++) {
    if (rootDirectory[i].filename[0] != 0x00) {
      printf("%s.%s\n", rootDirectory[i].filename, rootDirectory[i].extension);
    }
  }

  free(sectorBuffer);
  fclose(diskImageFile);

  return EXIT_SUCCESS;
}